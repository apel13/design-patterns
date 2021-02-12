#include <iostream>

#include "creational-patterns/builder/car_builder.h"
#include "creational-patterns/singleton/singleton.h"
#include "creational-patterns/prototype/shape.h"
#include "creational-patterns/factoryMethod/phone.h"


using namespace std;



void run_all();

int main() {
    run_all();
    return 0;
}

void singleton() {
    auto sender = Sender::getInstance("hello");
    sender->send();
}

void builder() {
    auto car1 = Car(
            CarParams()
                    .setName("Audi")
                    .setColor("Red")
                    .setMaxSpeed(350)
                    .setWeight(2'200.00)
                    .setPrice(8'000'000.00)
    );
    auto car2 = CarBuilder()
            .setName("Ferrari")
            .setColor("Green")
            .setMaxSpeed(380)
            .setWeight(1'800.00)
            .setPrice(9'000'000.00);

    cout << car1 << endl
         << car2 << endl;
}

void prototype() {
    std::shared_ptr<Shape> ptr_rect = std::make_shared<Rectangle>("shape");
    std::shared_ptr<Shape> ptr_circ = std::make_shared<Circle>("circle");

    ptr_rect->clone()->hello();
    ptr_circ->clone()->hello();
}

void factoryMethod() {
    auto method = [](const shared_ptr<Emulator> &emulator) {
        cout << emulator->getResult() << endl;
    };
    method(make_shared<IphoneEmulator>());
    method(make_shared<SamsungEmulator>());
}

void run_all() {
    singleton();
    builder();
    prototype();
    factoryMethod();
}