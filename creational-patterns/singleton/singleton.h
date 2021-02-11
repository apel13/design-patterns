#pragma once

#include <iostream>
#include <string> 

class Sender {
/*
---------------business logic---------------
*/
public:
    bool send() const;
private:
    const std::string _message;

    Sender(std::string);

/* 
---------------singleton realisation---------------
*/
public:
    Sender() = delete;
    Sender(const Sender&) = delete;
    Sender& operator=(const Sender&) = delete;

    static Sender* getInstance();
    static Sender* getInstance(std::string);

private:
    static Sender* sender;
};

// ---------------------------------------------

bool Sender::send() const {
    std::cout << "message: " << _message <<  std::endl;
    return true;
}

Sender::Sender(std::string message) 
    :_message(std::move(message)) {}

// ---------------------------------------------

Sender* Sender::sender = nullptr;

Sender* Sender::getInstance() {
    return sender;
}

Sender* Sender::getInstance(std::string message) {
    if (sender == nullptr) 
        sender = new Sender(std::move(message));
    return sender;
}


