#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>

template <typename T>
class Vector {
private:
    T* data;            //pointer to the array 
    std::size_t size_;
    std::size_t capacity_;

public:
    // Constructor
    Vector() {
        data = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    ~Vector() {
        delete[] data;
    }

    // Copy constructor  used when we create vector from another vector 
    // if we directly do data = other.data then both will point to the same memory 
    Vector(const Vector& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;

        if (capacity_ > 0) {
            data = new T[capacity_];

            for (std::size_t i = 0; i < size_; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }

    // Copy assignment
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            T* newData = nullptr;

            if (other.capacity_ > 0) {
                newData = new T[other.capacity_];

                for (std::size_t i = 0; i < other.size_; i++) {
                    newData[i] = other.data[i];
                }
            }

            delete[] data;

            data = newData;
            size_ = other.size_;
            capacity_ = other.capacity_;
        }

        return *this;
    }

    // Move constructor
    Vector(Vector&& other) noexcept {
        data = other.data;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    // Move assignment
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] data;

            data = other.data;
            size_ = other.size_;
            capacity_ = other.capacity_;

            other.data = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }

        return *this;
    }

    // Add element at the end
    void push_back(const T& value) {
        if (size_ == capacity_) {
            if (capacity_ == 0) {
                reserve(1);
            } else {
                reserve(capacity_ * 2);
            }
        }

        data[size_] = value;
        size_++;
    }

    // Remove last element
    // Time: O(1)
    void pop_back() {
        if (size_ > 0) {
            size_--;
        }
    }

    // Access element
    // Time: O(1)
    T& operator[](std::size_t index) {
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        return data[index];
    }

    // Access element with bounds checking
    // Time: O(1)
    T& at(std::size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    const T& at(std::size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    // Return number of elements
    // Time: O(1)
    std::size_t size() const {
        return size_;
    }

    // Return capacity
    // Time: O(1)
    std::size_t capacity() const {
        return capacity_;
    }

    // Check if vector is empty
    // Time: O(1)
    bool empty() const {
        return size_ == 0;
    }

    // Increase capacity
    // Time: O(n)
    void reserve(std::size_t newCapacity) {
        if (newCapacity <= capacity_) {
            return;
        }

        T* newData = new T[newCapacity];

        for (std::size_t i = 0; i < size_; i++) {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        capacity_ = newCapacity;
    }

    // Change size of vector
    // Time: O(n)
    void resize(std::size_t newSize) {
        if (newSize > capacity_) {
            reserve(newSize);
        }

        if (newSize > size_) {
            for (std::size_t i = size_; i < newSize; i++) {
                data[i] = T();
            }
        }

        size_ = newSize;
    }

    // Remove all elements
    // Time: O(1)
    void clear() {
        size_ = 0;
    }

    // Return pointer to first element
    // Time: O(1)
    T* begin() {
        return data;
    }

    const T* begin() const {
        return data;
    }

    // Return pointer after last element
    // Time: O(1)
    T* end() {
        return data + size_;
    }

    const T* end() const {
        return data + size_;
    }
};