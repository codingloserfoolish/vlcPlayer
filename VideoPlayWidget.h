#ifndef VIDEOPLAYWIDGET_H_
#define VIDEOPLAYWIDGET_H_
#include<qwidget.h>
#include"VlcMediaPlayer.h"
#include"VideoControlWidget.h"
class VideoPlayWidget :public QWidget
{
	Q_OBJECT
public:
	VideoPlayWidget(QWidget* parent = nullptr);
private:
	VideoControlWidget* m_control_widget;
};
#endif // !VIDEOPLAYWIDGET_H_
