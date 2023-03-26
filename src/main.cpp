#include <iostream>
#include <string>
#include <QApplication>
#include <QPushButton>

#include "message/message.h"

int main(int argc, char **argv)
{
    /*
    std::string input;
    std::cin >> input;
    Message message = Message(input);
    std::cout << message.get_user_input() << std::endl;
    */

    QApplication app(argc, argv);

    QPushButton button("Hello world !");
    button.show();

    return app.exec();
}
