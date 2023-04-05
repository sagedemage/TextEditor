#include <iostream>
#include <string>
#include <QApplication>
#include <QPushButton>
#include <QtWidgets>

#include "main_window/main_window.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    
    MainWindow mainWindow;
    mainWindow.resize(840, 630);
    mainWindow.show();

    return app.exec();
}
