#pragma once


#include <string>
#include <memory>


class Phone {
public:
    virtual ~Phone() = default;
    virtual std::string getInfo() const = 0;

    static void sendInfo(const Phone &phone);
};

class Samsung : public Phone {
public:
    std::string getInfo() const override;
};

class Iphone : public Phone {
public:
    std::string getInfo() const override;
};

// ---------------------------------------------------

class Emulator {
public:
    virtual ~Emulator() = default;
    virtual std::shared_ptr<Phone> getEmulator() const = 0;

    std::string getResult() const;
};

class SamsungEmulator : public Emulator {
public:
    std::shared_ptr<Phone> getEmulator() const override;
};

class IphoneEmulator : public Emulator {
public:
    std::shared_ptr<Phone> getEmulator() const override;
};

