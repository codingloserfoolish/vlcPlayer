#ifndef EXTRAMENU_H_
#define EXTRAMENU_H_
#include<qwidget.h>
//
//#define MENU_ACTION_TYPE(selection,type)\
//connect(this->addAction(QStringLiteral(selection)), &QAction::triggered, this, std::bind([this](int _t) {emit actionTrigger(_t); },type))
//
//class ExtraMenu :public QMenu
//{
//	Q_OBJECT
//public:
//	ExtraMenu(QWidget*parent=nullptr);
//	~ExtraMenu(){}
//signals:
//	void actionTrigger(int type);
//};

#define MENU_BUTTON_ACTION(type,selection)\
QPushButton* selection_##type = new QPushButton(QStringLiteral(selection), this);\
selection_##type->move(0, type*48);\
selection_##type->resize(360, 48);\
connect(selection_##type, &QPushButton::clicked, this, std::bind([this](int _t) {emit buttonType(_t); }, type))

class PopSettingMenu :public QWidget
{
	Q_OBJECT
public:
	PopSettingMenu(QWidget* parent = nullptr);
	~PopSettingMenu(){}

signals:
	void buttonType(int type);
protected:
	virtual void paintEvent(QPaintEvent* pe)override;
	virtual void leaveEvent(QEvent* e)override { this->hide(); }
};




#endif // !EXTRAMENU_H_
