#ifndef VIDEOPLAYWIDGET_H_
#define VIDEOPLAYWIDGET_H_
#include<qwidget.h>
#include"VlcMediaPlayer.h"
#include<qtimer.h>

class VideoControlWidget;
class VideoPlayWidget :public QWidget
{
	Q_OBJECT
public:
	VideoPlayWidget(QWidget* parent = nullptr);
	~VideoPlayWidget(){}
	void setPlayer(VlcMediaPlayer* player);
	void adjust_control_pos();
	void startTimer() { if (!m_hide_timer.isActive())m_hide_timer.start(); }
	void stopTimer() { if (m_hide_timer.isActive())m_hide_timer.stop(); }
public slots:
	void slot_OntimerOut();
protected:
	virtual bool event(QEvent*ev)override;
private:
	QTimer m_hide_timer;
	VlcMediaPlayer* m_player;
	VideoControlWidget* m_control_widget;
};
#endif // !VIDEOPLAYWIDGET_H_
