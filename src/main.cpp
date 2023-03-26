#include <iostream>
#include <string>
#include <QApplication>
#include <QPushButton>
#include <QtWidgets>

#include "message/message.h"
#include "main_window/main_window.h"

void print_text() {
    std::cout << "s" << std::endl;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    
    MainWindow mainWindow;
    mainWindow.resize(480, 360);
    mainWindow.show();

    mainWindow.setWindowTitle(
        QApplication::translate("toplevel", "QT5 Window"));

    return app.exec();
}
