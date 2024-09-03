#include"MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	:QMainWindow(parent)
{
	this->resize(800, 600);
	m_display_widget = new VideoPlayWidget(this);
	m_player.setWidget(m_display_widget);
	this->setCentralWidget(m_display_widget);
}

void MainWindow::playtest(const QString& name)
{
	m_player.change(name);
}
