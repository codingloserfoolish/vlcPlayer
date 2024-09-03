#include"VideoControlWidget.h"
#include<QVBoxLayout>
VideoControlWidget::VideoControlWidget(QWidget* parent)
	:QWidget(parent)
{
	if(parent!=nullptr)this->resize(parent->width(), parent->height() / 8);
	this.set
	this->setAttribute(Qt::WA_TranslucentBackground);
	QVBoxLayout* main_layer = new QVBoxLayout(this);
	m_video_duration = new QSlider(Qt::Horizontal,this);
	main_layer->addWidget(m_video_duration);
}
