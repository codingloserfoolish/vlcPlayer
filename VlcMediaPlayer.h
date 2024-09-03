#ifndef VLCMEDIAPLAYER_H_
#define VLCMEDIAPLAYER_H_
extern "C" {
#include<vlc/libvlc.h>
#include <vlc/libvlc_renderer_discoverer.h>
#include<vlc/libvlc_media.h>
#include<vlc/libvlc_media_player.h>
}
#include"VlcMedia.h"
#include<qmap.h>
#include<qwidget.h>

class VlcMediaPlayer
{
public:
	VlcMediaPlayer();
	~VlcMediaPlayer();
	void play(float pos=0);
	void change(const QString& name);
	void pause();
	void stop();
	void setWidget(QWidget* w);
private:
	libvlc_media_player_t* m_player;
	QMap<QString, VlcMedia*>m_media_list;
	QString m_current_media;
};


#endif // !VLCMEDIAPLAYER_H_
