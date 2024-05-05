#ifndef VECTORES_H
#define VECTORES_H

#include <string>

class OutOfRangeException {
public:
    OutOfRangeException(const std::string& message) : message(message) {}
    std::string getMessage() const { return message; }
private:
    std::string message;
};

template <typename T>
class MyVector {
private:
    T* arr;
    int size;
    int capacity;
public:
    MyVector() : size(0), capacity(1), arr(new T[1]) {}

    void push_back(const T& item) {
        if (size == capacity) {
            T* temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[size] = item;
        size++;
    }
    void pop_back() {
        if (size > 0) {
            size--;
        } else {
            throw OutOfRangeException("El vector está vacío");
        }
    }
    T& operator[](int index){
        if (index < size) {
            return arr[index];
        }
        else {
            throw OutOfRangeException("Índice fuera de rango");
        }
    }
    int getSize() const {
        return size;
    }
    bool empty() const {
        return size == 0;
    }
    void clear() {
        delete[] arr;
        size = 0;
        capacity = 1;
        arr = new T[capacity];
    }
    void resize(int newSize, const T& val = T()) {
        if (newSize > capacity) {
            T* temp = new T[newSize];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            for (int i = size; i < newSize; i++) {
                temp[i] = val;
            }
            delete[] arr;
            arr = temp;
            size = newSize;
            capacity = newSize;
        } else {
            size = newSize;
        }
    }
    void insert(int index, const T& val) {
        if (index < 0 || index > size) {
            throw OutOfRangeException("Índice fuera de rango");
        }
        if (size == capacity) {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < index; i++) {
                temp[i] = arr[i];
            }
            temp[index] = val;
            for (int i = index; i < size; i++) {
                temp[i + 1] = arr[i];
            }
            delete[] arr;
            arr = temp;
            size++;
            capacity *= 2;
        } else {
            for (int i = size; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = val;
            size++;
        }
    }
    ~MyVector() {
        delete[] arr;
    }
};
#endif // VECTORES_H
