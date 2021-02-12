#pragma once

#include "phone.h"

#include <iostream>
#include <string>
#include <sstream>


using namespace std;


std::string Iphone::getInfo() const {
    return "This is Apple";
}

std::string Samsung::getInfo() const {
    return  "This is Samsung";
}

void Phone::sendInfo(const Phone &phone) {
    cout << phone.getInfo() << endl;
}

std::string Emulator::getResult() const {
    auto phone = this->getEmulator();
    return "Emulator: " + phone->getInfo();
}

std::shared_ptr<Phone> SamsungEmulator::getEmulator() const {
    return make_shared<Samsung>();
}

std::shared_ptr<Phone> IphoneEmulator::getEmulator() const {
    return make_shared<Iphone>();
}
