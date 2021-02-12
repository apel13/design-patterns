#pragma once

#include <string>
#include <memory>


class Shape;
class Rectangle;
class Circle;


class Shape {
public:
    Shape();
    explicit Shape(std::string name);
    virtual ~Shape() = default;

    virtual std::shared_ptr<Shape> clone() const = 0;
    virtual void hello() const;

protected:
    double _x{}, _y{};
    std::string _name;
    std::string _color;
};

class Rectangle : public Shape {
public:
    explicit Rectangle(std::string name);

    std::shared_ptr<Shape> clone() const override;
    void hello() const override;

protected:
    double _w{}, _h{};
};

class Circle : public Shape {
public:
    explicit Circle(std::string name);

    std::shared_ptr<Shape> clone() const override;
    void hello() const override;
};