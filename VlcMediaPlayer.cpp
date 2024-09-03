#include"VlcMediaPlayer.h"
#include"VlcInstance.h"
#include<iostream>
VlcMediaPlayer::VlcMediaPlayer()
{
	m_player = libvlc_media_player_new(VlcInstance::instance());
}

VlcMediaPlayer::~VlcMediaPlayer()
{
	for (QMap<QString, VlcMedia*>::iterator it = m_media_list.begin(); it != m_media_list.end(); ++it)
	{
		delete it.value();
	}
	std::cout << "player released\n";
	libvlc_media_player_release(m_player);
}

void VlcMediaPlayer::play(float pos)
{
	if (!libvlc_media_player_get_media(m_player))return;
	libvlc_media_player_play(m_player);
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
	this->play((*it)->current_duration());
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

void VlcMediaPlayer::setWidget(QWidget* w)
{
	libvlc_media_player_set_hwnd(m_player, (void*)w->winId());
}
