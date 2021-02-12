cmake_minimum_required(VERSION 3.10)
project(design_patterns)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        "creational-patterns/builder"
        "creational-patterns/singleton"
        )

add_executable(design_patterns
        main.cpp
        creational-patterns/builder/car_builder.cpp
        creational-patterns/singleton/singleton.cpp
        creational-patterns/prototype/shape.cpp
        creational-patterns/prototype/shape.h creational-patterns/factoryMethod/phone.cpp creational-patterns/factoryMethod/phone.h)
