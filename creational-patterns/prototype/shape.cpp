#pragma once

#include "shape.h"

#include <iostream>

using namespace std;


Shape::Shape() = default;

Shape::Shape(string name)
        : _name(move(name)) {}

void Shape::hello() const {
    std::cout << "Hello from Shape" << std::endl;
}

// -------------------------------------------------------

Rectangle::Rectangle(std::string name)
        : Shape(std::move(name)) {}

std::shared_ptr<Shape> Rectangle::clone() const {
    return std::make_shared<Rectangle>(*this);
}

void Rectangle::hello() const {
    std::cout << "Hello from Rectangle" << std::endl;
}

Circle::Circle(std::string name)
        : Shape(std::move(name)) {}

std::shared_ptr<Shape> Circle::clone() const {
    return std::make_shared<Circle>(*this);
}

void Circle::hello() const {
    std::cout << "Hello from Circle" << std::endl;
}
