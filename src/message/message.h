#ifndef DATE_H
#define DATE_H

#include <string>;
#include <iostream>;

class Message {        // The class
    public:              // Access specifier
        std::string user_input;

        Message(std::string user_input);
        std::string get_user_input();
};

#endif