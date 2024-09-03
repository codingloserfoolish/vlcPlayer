#include"VlcInstance.h"
#include<iostream>

libvlc_ptr VlcInstance::m_instance;
libvlc_ptr::libvlc_ptr()
{
	m_instance = libvlc_new(0, NULL);
}

libvlc_ptr::~libvlc_ptr()
{
	std::cout << "instance released\n";
	libvlc_release(m_instance);
}
