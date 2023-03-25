#include <iostream>;
#include <string>;

#include "message/message.h";

int main() {
    std::string input;
    std::cin >> input;
    Message message = Message(input);
    std::cout << message.get_user_input() << std::endl;
}

