#include"MainWindow.h"
#include<qevent.h>
#include<qdebug.h>
MainWindow::MainWindow(QWidget* parent)
	:QMainWindow(parent)
{
	this->resize(800, 600);
	m_display_widget = new VideoPlayWidget(this);
	m_player.setWidget(m_display_widget);
	m_display_widget->setPlayer(&m_player);
	this->setCentralWidget(m_display_widget);
}

void MainWindow::playtest(const QString& name)
{
	m_player.change(name);
}

bool MainWindow::event(QEvent* ev)
{
	switch (ev->type())
	{
	case QEvent::Move:
	case QEvent::Resize:
		m_display_widget->adjust_control_pos(); break;
	case QEvent::Close:
		m_display_widget->close(); break;
	}
	return QMainWindow::event(ev);
}
