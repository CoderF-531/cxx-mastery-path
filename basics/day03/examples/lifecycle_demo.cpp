#include <iostream>
#include <string>
#include <utility>

class Tracer {
public:
    explicit Tracer(std::string name)
        : name_(std::move(name)) {
        std::cout << "construct " << name_ << '\n';
    }

    Tracer(const Tracer& other)
        : name_(other.name_ + "_copy") {
        std::cout << "copy construct " << name_ << " from " << other.name_ << '\n';
    }

    Tracer& operator=(const Tracer& other) {
        std::cout << "copy assign " << name_ << " from " << other.name_ << '\n';
        if (this != &other) {
            name_ = other.name_ + "_assigned";
        }
        return *this;
    }

    ~Tracer() {
        std::cout << "destroy " << name_ << '\n';
    }

private:
    std::string name_;
};

class Owner {
public:
    Owner()
        : first_("first"), second_("second"), third_("third") {
        std::cout << "Owner()\n";
    }

private:
    Tracer first_;
    Tracer second_;
    Tracer third_;
};

int main() {
    std::cout << "enter main\n";
    {
        Owner owner;
        std::cout << "inside scope\n";
    }
    std::cout << "leave main\n";
    return 0;
}
