#ifndef VIDEOCONTROLWIDGET_H_
#define VIDEOCONTROLWIDGET_H_
#include<qwidget.h>
#include<qslider.h>
class VideoControlWidget :public QWidget
{
	Q_OBJECT
public:
	VideoControlWidget(QWidget* parent = nullptr);
private:
	QSlider* m_video_duration;
};
#endif // !VIDEOCONTROLWIDGET_H_
