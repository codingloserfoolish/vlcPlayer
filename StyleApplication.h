#ifndef STYLEAPPLICATION_H_
#define STYLEAPPLICATION_H_
#include<qapplication.h>

class StyleApplication :public QApplication
{
	Q_OBJECT
public:
	StyleApplication(int argc, char** argv);
	virtual ~StyleApplication() {}
};
#endif // !STYLEAPPLICATION_H_
