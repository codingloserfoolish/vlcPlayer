#include"VlcMedia.h"
#include"VlcInstance.h"

#include<iostream>
VlcMedia::VlcMedia()
	:m_media(0),
	m_current_duration(0)
{
}
VlcMedia::VlcMedia(const QString& filename)
	:m_current_duration(0)
{
	m_media = libvlc_media_new_location(VlcInstance::instance(), (QString("file:///%1").arg(filename)).toLatin1());
}

VlcMedia::~VlcMedia()
{
	if (m_media)
	{
		std::cout << "media released\n";
		libvlc_media_release(m_media);
	}
}

void VlcMedia::setMedia(const QString& filename)
{
	if (m_media)
	{
		libvlc_media_release(m_media);
	}
	m_media = libvlc_media_new_location(VlcInstance::instance(), (QString("file:///%1").arg(filename)).toLatin1());
}
