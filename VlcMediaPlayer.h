#ifndef VLCMEDIAPLAYER_H_
#define VLCMEDIAPLAYER_H_
extern "C" {
#include<vlc/libvlc.h>
#include <vlc/libvlc_renderer_discoverer.h>
#include<vlc/libvlc_media.h>
#include<vlc/libvlc_media_player.h>
#include<vlc/libvlc_events.h>
}
#include"VlcMedia.h"
#include<qmap.h>
#include<qwidget.h>
#include<qmutex.h>



class VlcMediaPlayer:public QObject
{
	Q_OBJECT
public:
	VlcMediaPlayer();
	~VlcMediaPlayer();
	void continuePlay();
	void firstPlay(float pos=0);
	void changePos(float pos);
	void change(const QString& name);
	void pause();
	void stop();
	void setWidget(QWidget*w);

	void setQuiet(bool whether, int volume = 0);

	static void handles(const struct libvlc_event_t* p_event, void* p_data);

signals:
	void timeChanged(float pos);
	void startPlay(float pos,int second,int volume);



	/*static void* video_lock_callback(void* opaque, void** planes);
	static void  video_unlock_callback(void* opaque, void* picture,void* const* planes);
	static void  video_display_callback(void* opaque, void* picture);*/

	//QImage image;
private:
	//QWidget* m_dispaly;
	libvlc_media_player_t* m_player;
	libvlc_event_manager_t* m_manager;
	QMap<QString, VlcMedia*>m_media_list;
	QString m_current_media;
	//uchar*m_buffer;
};


#endif // !VLCMEDIAPLAYER_H_
