#include"ExtraMenu.h"
#include<qpushbutton.h>
#include<qpainter.h>
#include<functional>

//ExtraMenu::ExtraMenu(QWidget* parent)
//	:QMenu(parent)
//{
//	MENU_ACTION_TYPE("ѡ���ļ�", 0);
//}

PopSettingMenu::PopSettingMenu(QWidget* parent)
	:QWidget(parent)
{
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->resize(360, 48*5);
	MENU_BUTTON_ACTION(0, "���ļ�");

}

void PopSettingMenu::paintEvent(QPaintEvent* pe)
{
	QPainter p(this);
	p.fillRect(this->rect(), QColor(192,212,192,148));
	p.end();
}
