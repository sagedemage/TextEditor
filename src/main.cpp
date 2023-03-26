#include <iostream>
#include <string>
#include <QApplication>
#include <QPushButton>
#include <QtWidgets>

#include "message/message.h"

void print_text() {
    std::cout << "s" << std::endl;
}

int main(int argc, char **argv)
{
    /*
    std::string input;
    std::cin >> input;
    Message message = Message(input);
    std::cout << message.get_user_input() << std::endl;
    */

    QApplication app(argc, argv);


    QWidget *window = new QWidget;

    QGridLayout *layout = new QGridLayout(window);

    QPushButton *button1 = new QPushButton("Number 1");
    QPushButton *button2 = new QPushButton("Number 2");
    QPushButton *button3 = new QPushButton("Number 3");
    QPushButton *button4 = new QPushButton("Number 4");
    QPushButton *button5 = new QPushButton("Number 5");
    QPushButton *button6 = new QPushButton("Number 6");
    QPushButton *button7 = new QPushButton("Number 7");
    QPushButton *button8 = new QPushButton("Number 8");
    QPushButton *button9 = new QPushButton("Number 9");

    QObject::connect(button1, &QPushButton::clicked, &app, &QApplication::quit);

    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 0, 1);
    layout->addWidget(button3, 0, 2);
    layout->addWidget(button4, 1, 0);
    layout->addWidget(button5, 1, 1);
    layout->addWidget(button6, 1, 2);
    layout->addWidget(button7, 2, 0);
    layout->addWidget(button8, 2, 1);
    layout->addWidget(button9, 2, 2);

    window->resize(480, 360);
    window->show();

    window->setWindowTitle(
        QApplication::translate("toplevel", "QT5 Window"));

    return app.exec();
}

/*
QApplication app(argc, argv);
    QWidget window;
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget"));
    return app.exec();

    */