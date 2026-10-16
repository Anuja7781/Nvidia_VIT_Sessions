#include <iostream>
#include <utility>
#include "Vector.hpp"

int main() {
    Vector<int> v;

    std::cout << "Empty: " << v.empty() << "\n";

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Size: " << v.size() << "\n";
    std::cout << "Capacity: " << v.capacity() << "\n";

    std::cout << "Elements: ";

    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    std::cout << "v[1]: " << v[1] << "\n";
    std::cout << "v.at(2): " << v.at(2) << "\n";

    v.pop_back();

    std::cout << "After pop_back, size: " << v.size() << "\n";

    v.resize(5);

    std::cout << "After resize, size: " << v.size() << "\n";

    std::cout << "Elements: ";

    for (std::size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    std::cout << "\n";

    v.clear();

    std::cout << "After clear, empty: " << v.empty() << "\n";

        // Copy constructor
    Vector<int> a;
    a.push_back(100);
    a.push_back(200);

    Vector<int> b = a;

    std::cout << "Copy constructor: ";
    for (std::size_t i = 0; i < b.size(); i++) {
        std::cout << b[i] << " ";
    }
    std::cout << "\n";

    // Copy assignment
    Vector<int> c;
    c = a;

    std::cout << "Copy assignment: ";
    for (std::size_t i = 0; i < c.size(); i++) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";

    // Move constructor
    Vector<int> d = std::move(a);

    std::cout << "Move constructor: ";
    for (std::size_t i = 0; i < d.size(); i++) {
        std::cout << d[i] << " ";
    }
    std::cout << "\n";

    // Move assignment
    Vector<int> e;
    e = std::move(b);

    std::cout << "Move assignment: ";
    for (std::size_t i = 0; i < e.size(); i++) {
        std::cout << e[i] << " ";
    }
    std::cout << "\n";

    return 0;
}