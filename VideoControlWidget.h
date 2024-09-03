#ifndef VIDEOCONTROLWIDGET_H_
#define VIDEOCONTROLWIDGET_H_
#include<qwidget.h>
#include<qslider.h>
#include<qlabel.h>
#include"VlcMediaPlayer.h"
#include"ExtraMenu.h"
class VideoPlayWidget;
class SwitchLabel :public QLabel
{
	Q_OBJECT
public:
	SwitchLabel(const QString&origin,const QString&forswitch, QWidget*parent);
	~SwitchLabel();
	bool isOrigin()const { return m_origin; }
signals:
	void switched(bool isOrigin);
protected:
	virtual void mousePressEvent(QMouseEvent* e)override;
	virtual void mouseReleaseEvent(QMouseEvent* e)override;
private:
	bool m_isOrigin;
	QPixmap*m_origin;
	QPixmap*m_for_switch;
};



class VideoControlWidget :public QWidget
{
	Q_OBJECT
public:
	VideoControlWidget(QWidget* parent = nullptr);
	~VideoControlWidget();
	void setPlayer(VlcMediaPlayer* player); //{ m_player = player; };
public slots:
	void slot_onVideoStartPlay(float pos,int second,int volume);
	void slot_onSliderPressed();
	void slot_onSliderReleased();
	void slot_onSliderTimeChanged(float value);
	void slot_onVideoSwitchedChanged(bool);
	void slot_onAudioSwitchedChanged(bool);
	void slot_onAudioValueChanged(int volume);
	void slot_onPopCtxMenu();
	void slot_onDealMenuSignals(int type);
protected:
	virtual void paintEvent(QPaintEvent* pe)override;
	virtual void closeEvent(QCloseEvent*)override;
	virtual void enterEvent(QEvent* e)override;
	virtual void leaveEvent(QEvent* e)override;
private:
	PopSettingMenu* m_popCtxMenu;
	VlcMediaPlayer* m_player;

	QSlider* m_video_duration;
	QSlider* m_audio_volume;
	bool m_isQuiet;
};
#endif // !VIDEOCONTROLWIDGET_H_
