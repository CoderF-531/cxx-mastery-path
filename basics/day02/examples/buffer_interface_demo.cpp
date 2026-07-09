#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>

class Buffer {
public:
    Buffer() = default;

    ~Buffer() {
        delete[] data_;
    }

    Buffer(const Buffer& other)
        : size_(other.size_), capacity_(other.capacity_), data_(nullptr) {
        if (capacity_ != 0) {
            data_ = new int[capacity_];
            for (std::size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
    }

    Buffer& operator=(Buffer other) {
        swap(other);
        return *this;
    }

    void push_back(int value) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 4 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    int& operator[](std::size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Buffer index out of range");
        }
        return data_[index];
    }

    const int& operator[](std::size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Buffer index out of range");
        }
        return data_[index];
    }

    std::size_t size() const {
        return size_;
    }

    std::size_t capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

private:
    void reserve(std::size_t new_capacity) {
        if (new_capacity <= capacity_) {
            return;
        }

        int* new_data = new int[new_capacity];
        for (std::size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    void swap(Buffer& other) {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(data_, other.data_);
    }

private:
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
    int* data_ = nullptr;
};

void print_buffer(const Buffer& buffer) {
    for (std::size_t i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    Buffer buffer;
    buffer.push_back(10);
    buffer.push_back(20);
    buffer.push_back(30);

    buffer[1] = 200;
    print_buffer(buffer);

    const Buffer& const_buffer = buffer;
    std::cout << "size: " << const_buffer.size() << '\n';
    std::cout << "first: " << const_buffer[0] << '\n';

    try {
        std::cout << const_buffer[100] << '\n';
    } catch (const std::out_of_range& e) {
        std::cout << "caught: " << e.what() << '\n';
    }

    return 0;
}
