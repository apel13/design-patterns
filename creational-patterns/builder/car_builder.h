#pragma once

#include <iostream>
#include <string>

class CarParams;
class CarBuilder;
class Car;


class Car {
private:
    // variant 1: check params in builder and construct from builder 
    Car(std::string name, std::string color, double price, double max_speed, double weight);
    friend class CarBuilder;
public:
    // variant 2: check params in car constructor 
    Car(const CarParams&);

public:
    uint32_t id() const;
    const std::string& name() const;
    const std::string& color() const;
    double price() const;
    double maxSpeed() const;
    double weight() const;

private:
    const uint32_t _id;
    std::string _name;
    std::string _color;
    double _price;
    double _max_speed;
    double _weight;

private:
    static uint32_t _gID;
};

std::ostream &operator<<(std::ostream &os, const Car &car);

class CarParams {
    friend class Car;
public:
    CarParams& setName(std::string name);
    CarParams& setColor(std::string color);
    CarParams& setPrice(double price);
    CarParams& setMaxSpeed(double max_speed);
    CarParams& setWeight(double weight);

private:
    std::string _name;
    std::string _color;
    double _price;
    double _max_speed;
    double _weight;
};

class CarBuilder {
public:
    CarBuilder& setName(std::string name);
    CarBuilder& setColor(std::string color);
    CarBuilder& setPrice(double price);
    CarBuilder& setMaxSpeed(double max_speed);
    CarBuilder& setWeight(double weight);

    Car Build() const;
    operator Car() const;

private:
    std::string _name;
    std::string _color;
    double _price;
    double _max_speed;
    double _weight;
};


