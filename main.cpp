#include "test005.h"

#include <QtGui>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TdieGUI dieGUI;
    dieGUI.show();

    return a.exec();
}
