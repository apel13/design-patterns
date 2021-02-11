#include <iostream>

#include "creational-patterns/builder/car_builder.h"
#include "creational-patterns/singleton/singleton.h"


using namespace std;


int main() {
    // singleton
    {
        auto sender = Sender::getInstance("hello");
        sender->send();
    }

    // builder
    {
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

    return 0;
}