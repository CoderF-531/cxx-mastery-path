#include <iostream>
#include <string>

void add_one_by_value(int x) {
    ++x;
}

void add_one_by_reference(int& x) {
    ++x;
}

void print_name(const std::string& name) {
    std::cout << "name: " << name << '\n';
}

void reset_pointer_copy(int* p) {
    p = nullptr;
}

void reset_pointer_ref(int*& p) {
    p = nullptr;
}

int main() {
    int value = 10;

    add_one_by_value(value);
    std::cout << "after value: " << value << '\n';

    add_one_by_reference(value);
    std::cout << "after reference: " << value << '\n';

    std::string name = "CoderF";
    print_name(name);
    print_name("temporary");

    int x = 42;
    int* p = &x;

    reset_pointer_copy(p);
    std::cout << "after pointer copy reset: " << (p == nullptr) << '\n';

    reset_pointer_ref(p);
    std::cout << "after pointer reference reset: " << (p == nullptr) << '\n';

    return 0;
}
