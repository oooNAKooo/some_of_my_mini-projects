#include "triangle_prism_window.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    TrianglePrismWindow w;
    w.show();
    return a.exec();
}
