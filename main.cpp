#include<qapplication.h>
#include"StyleApplication.h"
#include"MainWindow.h"

int main(int argc,char**argv)
{
    StyleApplication app(argc,argv);
    MainWindow w;
    w.show();
    //w.playtest("./test.mp4");
    return app.exec();
};