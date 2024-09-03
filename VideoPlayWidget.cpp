#include"VideoPlayWidget.h"
#include<qpainter.h>
#include<qevent.h>
#include"VideoControlWidget.h"
#include<qdebug.h>


VideoPlayWidget::VideoPlayWidget(QWidget* parent)
	:QWidget(parent),
	m_hide_timer(this)
{
	m_hide_timer.setInterval(1000);
	this->resize(800, 600);
	m_control_widget = new VideoControlWidget(this);
	connect(&m_hide_timer, &QTimer::timeout, this,&VideoPlayWidget::slot_OntimerOut);
}

void VideoPlayWidget::setPlayer(VlcMediaPlayer* player)
{
	m_control_widget->setPlayer(player);
}

void VideoPlayWidget::adjust_control_pos()
{
	m_control_widget->resize(this->width(), m_control_widget->height());
	m_control_widget->move(mapToGlobal(this->pos())+QPoint(0,this->height()-m_control_widget->height()));
}

void VideoPlayWidget::slot_OntimerOut()
{
	m_control_widget->hide();
	m_hide_timer.stop();
}

bool VideoPlayWidget::event(QEvent* ev)
{
	switch (ev->type())
	{
	case QEvent::Show:
		m_control_widget->show();
		m_hide_timer.start();
		break;
	case QEvent::Hide:
		m_control_widget->hide();
		break;
	case QEvent::Enter:
	{
		if (m_hide_timer.isActive())
			m_hide_timer.stop();
		if (!m_control_widget->isVisible())
			m_control_widget->show();
	}
		break;
	case QEvent::Leave:
		if (!m_hide_timer.isActive())m_hide_timer.start();
		break;
	case QEvent::Close:
		m_control_widget->close(); break;
	default:
		break;
	}
	return QWidget::event(ev);
}
