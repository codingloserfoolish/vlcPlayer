#ifndef VLCINSTANCE_H_
#define VLCINSTANCE_H_
#include<mutex>
extern "C" {
#include<vlc/libvlc.h>
}

class libvlc_ptr
{
public:
	libvlc_ptr();
	~libvlc_ptr();
	operator libvlc_instance_t* () { return m_instance; };
private:
	libvlc_instance_t* m_instance;
};


class VlcInstance
{
public:
	VlcInstance(const VlcInstance&) = delete;
	VlcInstance& operator=(const VlcInstance&) = delete;

	static libvlc_instance_t* instance()
	{ 
		return m_instance;
	}
private:
	VlcInstance(){}

	static libvlc_ptr m_instance;
};

#endif // !INSTANCE_H_
