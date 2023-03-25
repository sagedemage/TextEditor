// Create a Car class with some attributes

#include "message.h";

Message::Message(std::string user_input) {
    this->user_input = user_input;
}

std::string Message::get_user_input() {
    return user_input;
}

