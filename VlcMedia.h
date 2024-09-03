#ifndef VLCMEDIA_H_
#define VLCMEDIA_H_

extern "C" {
#include<vlc/libvlc.h>
#include <vlc/libvlc_renderer_discoverer.h>
#include<vlc/libvlc_media.h>
}
#include<qstring.h>

class VlcMedia
{
public:
	VlcMedia();
	VlcMedia(const QString&filename);
	~VlcMedia();
	void setMedia(const QString& filename);
	operator libvlc_media_t* () { return m_media; }
	float current_duration()const {return m_current_duration;}
	void set_duration(float dur) { m_current_duration = dur; }
private:
	float m_current_duration;
	libvlc_media_t* m_media;
};

#endif // !VLCMEDIA_H_
