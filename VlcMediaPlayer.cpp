#include"VlcMediaPlayer.h"
#include"VlcInstance.h"

#include<qdebug.h>
#include<iostream>


QMutex g_buffer_lock;

VlcMediaPlayer::VlcMediaPlayer()
{
	//m_buffer = new uchar[360*640*4];
	m_player = libvlc_media_player_new(VlcInstance::instance());
	m_manager = libvlc_media_player_event_manager(m_player);

	

	libvlc_video_set_mouse_input(m_player, false);
	libvlc_video_set_key_input(m_player, false);
}

VlcMediaPlayer::~VlcMediaPlayer()
{
	for (QMap<QString, VlcMedia*>::iterator it = m_media_list.begin(); it != m_media_list.end(); ++it)
	{
		delete it.value();
	}
	std::cout << "player released\n";
	//delete[]m_buffer;
	libvlc_media_player_release(m_player);
}

void VlcMediaPlayer::continuePlay()
{
	if (!libvlc_media_player_get_media(m_player))return;
	libvlc_media_player_play(m_player);
}

void VlcMediaPlayer::firstPlay(float pos)
{
	if (!libvlc_media_player_get_media(m_player))return;
	libvlc_media_player_play(m_player);
	libvlc_media_player_set_position(m_player, pos);
}

void VlcMediaPlayer::changePos(float pos)
{
	libvlc_media_player_set_position(m_player, pos);
}

void VlcMediaPlayer::change(const QString& name)
{
	if (libvlc_media_player_is_playing(m_player))
	{
		libvlc_media_player_pause(m_player);
	}
	QMap<QString, VlcMedia*>::iterator media = m_media_list.find(m_current_media);
	if (media != m_media_list.end())
	{
		(*media)->set_duration(libvlc_media_player_get_position(m_player));
	}
	m_current_media = name;
	QMap<QString, VlcMedia*>::iterator it = m_media_list.find(name);
	if (it == m_media_list.end())
	{
		it = m_media_list.insert(name, new VlcMedia(name));
	}
	libvlc_media_player_set_media(m_player, *(*it));
	this->firstPlay((*it)->current_duration());
}

void VlcMediaPlayer::pause()
{
	if (libvlc_media_player_can_pause(m_player))
	{
		libvlc_media_player_pause(m_player);
	}
}

void VlcMediaPlayer::stop()
{
	if(libvlc_media_player_get_media(m_player))
	libvlc_media_player_stop(m_player);
}

void VlcMediaPlayer::setWidget(QWidget*w)
{
	
	/*m_dispaly = w;
	libvlc_video_set_callbacks(m_player, video_lock_callback, video_unlock_callback, video_display_callback,this);
	libvlc_video_set_format(m_player, "RGBA", 640, 360, 640 * 4);*/
	libvlc_media_player_set_hwnd(m_player,(void*) w->winId());
	libvlc_event_attach(m_manager, libvlc_MediaPlayerTimeChanged, handles, this);
	libvlc_event_attach(m_manager, libvlc_MediaPlayerPlaying, handles, this);
}

void VlcMediaPlayer::setQuiet(bool whether,int volume )
{
	if (whether)
		libvlc_audio_set_volume(m_player, volume);
	else
		libvlc_audio_set_volume(m_player, 0);
}

void VlcMediaPlayer::handles(const libvlc_event_t* p_event, void* p_data)
{
	VlcMediaPlayer* player = (VlcMediaPlayer*)p_data;
	switch (p_event->type)
	{
	case libvlc_MediaPlayerTimeChanged:
		emit player->timeChanged(libvlc_media_player_get_position(player->m_player)); break;
	case libvlc_MediaPlayerPlaying:
		emit player->startPlay(libvlc_media_player_get_position(player->m_player), libvlc_media_player_get_length(player->m_player),libvlc_audio_get_volume(player->m_player)); break;
	default:
		break;
	}
}

//void* VlcMediaPlayer::video_lock_callback(void* opaque, void** planes)
//{
//	g_buffer_lock.lock();
//	VlcMediaPlayer* player = (VlcMediaPlayer*)opaque;
//	memset(player->m_buffer, 0, 640 * 360 * 4);
//	return player->m_buffer;
//}
//
//void VlcMediaPlayer::video_unlock_callback(void* opaque, void* picture, void* const* planes)
//{
//	VlcMediaPlayer* player = (VlcMediaPlayer*)opaque;
//	player->image = QImage(player->m_buffer, 640, 360, QImage::Format_ARGB32);
//	g_buffer_lock.unlock();
//	player->m_dispaly->update();
//}
//
//void VlcMediaPlayer::video_display_callback(void* opaque, void* picture)
//{
//
//}
