#include <Weekly.h>
#include <QApplication>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Weekly weekly;
    weekly.show();
    return a.exec();
}
