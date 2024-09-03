#include"VideoPlayWidget.h"
#include<QVBoxLayout>
#include<QSpacerItem>
VideoPlayWidget::VideoPlayWidget(QWidget* parent)
	:QWidget(parent)
{
	QVBoxLayout* main_layer = new QVBoxLayout(this);
	main_layer->addSpacerItem(new QSpacerItem(36, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));
	m_control_widget = new VideoControlWidget(this);
	main_layer->addWidget(m_control_widget);
}
