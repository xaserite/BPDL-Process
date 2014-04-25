#include <QtGui/QApplication>

#include "graphplot.h"
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    GraphPlot G(QSize(800,320));
    G.show();
    return a.exec();
}

