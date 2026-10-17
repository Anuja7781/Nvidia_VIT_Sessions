#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Matrix {
private:
    size_t r;
    size_t c;
    T* data;

public:

    // Constructor
    Matrix(size_t rows, size_t cols, const T& value = T())
        : r(rows), c(cols) {

        data = new T[r * c];

        for (size_t i = 0; i < r * c; i++) {
            data[i] = value;
        }
    }

    // Destructor
    ~Matrix() {
        delete[] data;
    }

    // Copy constructor
    Matrix(const Matrix& other)
        : r(other.r), c(other.c) {

        data = new T[r * c];

        for (size_t i = 0; i < r * c; i++) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment
    Matrix& operator=(const Matrix& other) {

        if (this == &other)
            return *this;

        T* newData = new T[other.r * other.c];

        for (size_t i = 0; i < other.r * other.c; i++) {
            newData[i] = other.data[i];
        }

        delete[] data;

        data = newData;
        r = other.r;
        c = other.c;

        return *this;
    }

    // Move constructor
    Matrix(Matrix&& other) noexcept
        : r(other.r), c(other.c), data(other.data) {

        other.r = 0;
        other.c = 0;
        other.data = nullptr;
    }

    // Move assignment
    Matrix& operator=(Matrix&& other) noexcept {

        if (this == &other)
            return *this;

        delete[] data;

        r = other.r;
        c = other.c;
        data = other.data;

        other.r = 0;
        other.c = 0;
        other.data = nullptr;

        return *this;
    }

    // Number of rows
    size_t rows() const {
        return r;
    }

    // Number of columns
    size_t cols() const {
        return c;
    }

    // Element access
    T& operator()(size_t i, size_t j) {
        return data[i * c + j];
    }

    const T& operator()(size_t i, size_t j) const {
        return data[i * c + j];
    }

    // Bounds-checked access
    T& at(size_t i, size_t j) {

        if (i >= r || j >= c)
            throw out_of_range("Matrix index out of bounds");

        return data[i * c + j];
    }

    const T& at(size_t i, size_t j) const {

        if (i >= r || j >= c)
            throw out_of_range("Matrix index out of bounds");

        return data[i * c + j];
    }

    // Fill entire matrix
    void fill(const T& value) {

        for (size_t i = 0; i < r * c; i++) {
            data[i] = value;
        }
    }

    // Resize matrix
    void resize(size_t newRows, size_t newCols) {

        T* newData = new T[newRows * newCols];

        for (size_t i = 0; i < newRows * newCols; i++) {
            newData[i] = T();
        }

        size_t minRows = min(r, newRows);
        size_t minCols = min(c, newCols);

        for (size_t i = 0; i < minRows; i++) {
            for (size_t j = 0; j < minCols; j++) {
                newData[i * newCols + j] = data[i * c + j];
            }
        }

        delete[] data;

        data = newData;
        r = newRows;
        c = newCols;
    }
};


int main() {

    Matrix<int> m(2, 3, 5);

    m(0, 1) = 10;

    cout << m(0, 1) << endl;

    cout << m.at(1, 2) << endl;

    m.fill(7);

    m.resize(3, 4);

    cout << m.rows() << " " << m.cols() << endl;

    return 0;
}