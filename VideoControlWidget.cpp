#include"VideoControlWidget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QMouseEvent>
#include<QPainter>
#include"VideoPlayWidget.h"
#include<qfiledialog.h>
#include<qdebug.h>

SwitchLabel::SwitchLabel(const QString& origin, const QString& forswitch, QWidget* parent)
	:QLabel(parent),
	m_isOrigin(true)
{
	this->setFixedSize(36, 36);
	this->setScaledContents(true);
	if (origin.isEmpty())
	{
		m_origin = 0;
		m_for_switch = 0;
		return;
	}
	m_origin = new QPixmap(origin);
	m_origin->scaled(this->size(), Qt::KeepAspectRatio);
	this->setPixmap(*m_origin);
	if (forswitch.isEmpty())
	{
		m_for_switch = 0;
		return;
	}
	m_for_switch = new QPixmap(forswitch);
	m_for_switch->scaled(this->size(), Qt::KeepAspectRatio);
}

SwitchLabel::~SwitchLabel()
{
	if (m_origin)delete m_origin;
	if (m_for_switch)delete m_for_switch;
}

void SwitchLabel::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		this->resize(this->width() - 4, this->height() - 4);
		this->move(this->pos()+QPoint(2,2));
	}
}

void SwitchLabel::mouseReleaseEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		this->resize(this->width() + 4, this->height() + 4);
		this->move(this->pos() + QPoint(-2, -2));
		m_isOrigin = !m_isOrigin;
		if (m_isOrigin)
		{
			if(m_origin)this->setPixmap(*m_origin);
		}
		else
		{
			if (m_for_switch)this->setPixmap(*m_for_switch);
		}
		emit switched(m_isOrigin);

	}
}



VideoControlWidget::VideoControlWidget(QWidget* parent)
	:QWidget(parent),
	m_player(0),
	m_isQuiet(false)
{
	this->setWindowFlags(Qt::FramelessWindowHint|Qt::Window);
	this->setAttribute(Qt::WA_TranslucentBackground);
	if (parent != nullptr)
	{
		this->resize(parent->width(), parent->height() / 6);
	}

	QVBoxLayout* main_layer = new QVBoxLayout(this);
	m_video_duration = new QSlider(Qt::Horizontal, this);
	main_layer->addWidget(m_video_duration);
	
	m_popCtxMenu = new PopSettingMenu;


	QHBoxLayout* ting_layer = new QHBoxLayout;
	main_layer->addLayout(ting_layer);


	SwitchLabel* playpause_lab = new SwitchLabel("./img/play.png","./img/pause.png",this);
	ting_layer->addWidget(playpause_lab);
	ting_layer->addSpacerItem(new QSpacerItem(600, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));

	SwitchLabel* audioctrl_lab = new SwitchLabel("./img/noisy.png", "./img/quiet.png", this);
	m_audio_volume = new QSlider(Qt::Horizontal,this);
	m_audio_volume->setFixedWidth(88);
	ting_layer->addWidget(audioctrl_lab);
	ting_layer->addWidget(m_audio_volume);


	SwitchLabel* more_lab = new SwitchLabel("./img/more.png", "", this);
	ting_layer->addWidget(more_lab);
	connect(m_popCtxMenu, &PopSettingMenu::buttonType, this, &VideoControlWidget::slot_onDealMenuSignals);
	connect(m_video_duration, &QSlider::sliderPressed, this, &VideoControlWidget::slot_onSliderPressed);
	connect(m_video_duration, &QSlider::sliderReleased, this, &VideoControlWidget::slot_onSliderReleased);
	connect(m_audio_volume, &QSlider::valueChanged, this, &VideoControlWidget::slot_onAudioValueChanged);
	connect(audioctrl_lab, &SwitchLabel::switched, this, &VideoControlWidget::slot_onAudioSwitchedChanged);
	connect(playpause_lab, &SwitchLabel::switched, this, &VideoControlWidget::slot_onVideoSwitchedChanged);
	connect(more_lab, &SwitchLabel::switched, this, &VideoControlWidget::slot_onPopCtxMenu);
}

VideoControlWidget::~VideoControlWidget()
{
	 delete m_popCtxMenu; 
}

void VideoControlWidget::setPlayer(VlcMediaPlayer* player)
{
	m_player = player;
	connect(m_player, &VlcMediaPlayer::timeChanged, this, &VideoControlWidget::slot_onSliderTimeChanged);
	connect(m_player,&VlcMediaPlayer::startPlay,this,&VideoControlWidget::slot_onVideoStartPlay);
}

void VideoControlWidget::paintEvent(QPaintEvent* pe)
{
	QPainter p(this);
	p.fillRect(0, 0, this->width(), this->height(), QColor(192, 192, 192, 127));
	p.end();
}

void VideoControlWidget::closeEvent(QCloseEvent*)
{
	if(m_popCtxMenu->isVisible())
	m_popCtxMenu->close();
}

void VideoControlWidget::enterEvent(QEvent* e)
{
	((VideoPlayWidget*)this->parent())->stopTimer();
}

void VideoControlWidget::leaveEvent(QEvent* e)
{
	((VideoPlayWidget*)this->parent())->startTimer();
}

void VideoControlWidget::slot_onVideoStartPlay(float pos, int second,int volume)
{
	m_video_duration->setMaximum(second);
	m_video_duration->setValue(second * pos);
	m_audio_volume->blockSignals(true);
	m_audio_volume->setValue(volume);
	m_audio_volume->blockSignals(false);
}

void VideoControlWidget::slot_onSliderPressed()
{
	if(m_player)
	disconnect(m_player, &VlcMediaPlayer::timeChanged, this, &VideoControlWidget::slot_onSliderTimeChanged);
}

void VideoControlWidget::slot_onSliderReleased()
{	
	if (m_player)
	{
		m_player->changePos((float)m_video_duration->value()/(float)m_video_duration->maximum());
		connect(m_player, &VlcMediaPlayer::timeChanged, this, &VideoControlWidget::slot_onSliderTimeChanged);
	}
}

void VideoControlWidget::slot_onSliderTimeChanged(float value)
{
	m_video_duration->setValue(m_video_duration->maximum()*value);
}

void VideoControlWidget::slot_onVideoSwitchedChanged(bool isorigin)
{
	if (!m_player)return;
	if (isorigin)
	{
		m_player->continuePlay();
	}
	else
	{
		m_player->pause();
	}
}

void VideoControlWidget::slot_onAudioSwitchedChanged(bool origin)
{
	if (!m_player)return;
	m_player->setQuiet(origin, m_audio_volume->value());
	m_isQuiet = origin;
}

void VideoControlWidget::slot_onAudioValueChanged(int volume)
{
	if (m_player&&m_isQuiet)
	{
		m_player->setQuiet(true, volume);
	}
}

void VideoControlWidget::slot_onPopCtxMenu()
{
	if (m_popCtxMenu->isVisible()) { m_popCtxMenu->raise(); return; }
	m_popCtxMenu->move(this->x() + this->width() - m_popCtxMenu->width(), this->y() + this->height() - m_popCtxMenu->height());
	m_popCtxMenu->show();
}

void VideoControlWidget::slot_onDealMenuSignals(int type)
{
	if (type == 0)
	{
		QString filename=QFileDialog::getOpenFileName(0, QStringLiteral("Ñ¡ÔñÎÄ¼þ"), "./", "*.mp4;*.wav;*.flv;*.avi;*.mp3;*.ogg");
		if (filename.isEmpty())return;
		m_player->change(filename);


	}
}
