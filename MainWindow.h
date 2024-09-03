#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_
#include<qmainwindow.h>
#include"VideoPlayWidget.h"
#include"VlcMediaPlayer.h"

class MainWindow :public QMainWindow
{
public:
	MainWindow(QWidget* parent = nullptr);
	void playtest(const QString& name);
private:
	VideoPlayWidget* m_display_widget;
	VlcMediaPlayer m_player;
};
#endif // !MAINWINDOW_H_
