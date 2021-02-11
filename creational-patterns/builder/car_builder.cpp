#include "car_builder.h"

#include <iomanip>

using namespace std;


uint32_t Car::_gID = 1000;

Car::Car(std::string name, std::string color,
         double price, double max_speed, double weight)
        : _id(_gID++), _name(move(name)), _color(move(color)), _price(price), _max_speed(max_speed), _weight(weight) {}

Car::Car(const CarParams &params)
        : _id(_gID++) {
    if (params._name.empty() ||
        params._color.empty() ||
        params._price < 0.0 ||
        params._max_speed < 0.0 ||
        params._weight < 0.0) {
        throw std::invalid_argument("invalid arguments for car");
    }
    _name = params._name;
    _color = params._color;
    _price = params._price;
    _max_speed = params._max_speed;
    _weight = params._weight;
}

uint32_t Car::id() const {
    return _id;
}

const string &Car::name() const {
    return _name;
}

const string &Car::color() const {
    return _color;
}

double Car::price() const {
    return _price;
}

double Car::maxSpeed() const {
    return _max_speed;
}

double Car::weight() const {
    return _weight;
}

std::ostream &operator<<(std::ostream &os, const Car &car) {
    os << fixed << setprecision(2);
    return os
    << "["
    << setw(5) << left << car.id()
    << setw(8) << left << car.name()
    << setw(10) << left << car.color()
    << setw(11) << left << car.price()
    << setw(10) << left << car.maxSpeed()
    << setw(7) << left << car.weight()
    << "]";
}

// ---------------------------CarParams-----------------------------

CarParams &CarParams::setName(std::string name) {
    _name = move(name);
    return *this;
}

CarParams &CarParams::setColor(std::string color) {
    _color = move(color);
    return *this;
}

CarParams &CarParams::setPrice(double price) {
    _price = price;
    return *this;
}

CarParams &CarParams::setMaxSpeed(double max_speed) {
    _max_speed = max_speed;
    return *this;
}

CarParams &CarParams::setWeight(double weight) {
    _weight = weight;
    return *this;
}

// ---------------------------CarBuilder-----------------------------

CarBuilder &CarBuilder::setName(std::string name) {
    _name = move(name);
    return *this;
}

CarBuilder &CarBuilder::setColor(std::string color) {
    _color = move(color);
    return *this;
}

CarBuilder &CarBuilder::setPrice(double price) {
    _price = price;
    return *this;
}

CarBuilder &CarBuilder::setMaxSpeed(double max_speed) {
    _max_speed = max_speed;
    return *this;
}

CarBuilder &CarBuilder::setWeight(double weight) {
    _weight = weight;
    return *this;
}

Car CarBuilder::Build() const  {
    if (_name.empty() ||
        _color.empty() ||
        _price < 0.0 ||
        _max_speed < 0.0 ||
        _weight < 0.0)
    {
        throw std::invalid_argument("invalid arguments for car build");
    }
    return Car(_name, _color, _price, _max_speed, _weight);
}

CarBuilder::operator Car() const {
    return Build();
}

