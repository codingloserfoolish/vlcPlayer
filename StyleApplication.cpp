#include "StyleApplication.h"
#include<qfiledialog.h>
#include<qdebug.h>
StyleApplication::StyleApplication(int argc, char** argv)
	:QApplication(argc,argv)
{
	QDir dir("../style/");
	dir.setFilter(QDir::Files | QDir::NoSymLinks);
	dir.setNameFilters({ "*.qss" });
	QFileInfoList list = dir.entryInfoList();
	for (QFileInfo& info : list)
	{
		if (info.isFile())
		{
			QFile style_file(info.absoluteFilePath());
			style_file.open(QIODevice::ReadOnly);
			this->setStyleSheet(style_file.readAll());
			style_file.close();
		}
	}
}
