
#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    T* _data;
    int _capacity;
    int _size;

    void expand() {
        int newCapacity = (_capacity == 0) ? 1 : _capacity * 2;
        T* newData = new T[newCapacity];

        for (int i = 0; i < _size; i++) {
            newData[i] = _data[i];
        }

        delete[] _data;
        _data = newData;
        _capacity = newCapacity;
    }

public:
    Stack() {
        _capacity = 2;
        _size = 0;
        _data = new T[_capacity];
    }

    ~Stack() {
        delete[] _data;
    }

    Stack(const Stack& other) {
        _capacity = other._capacity;
        _size = other._size;
        _data = new T[_capacity];

        for (int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            T* newData = new T[other._capacity];

            for (int i = 0; i < other._size; i++) {
                newData[i] = other._data[i];
            }

            delete[] _data;
            _data = newData;
            _capacity = other._capacity;
            _size = other._size;
        }

        return *this;
    }

    void push(const T& x) {
        if (_size == _capacity) {
            expand();
        }

        _data[_size] = x;
        _size++;
    }

    void pop() {
        if (_size > 0) {
            _size--;
        }
    }

    T& top() {
        return _data[_size - 1];
    }

    const T& top() const {
        return _data[_size - 1];
    }

    int size() const {
        return _size;
    }

    int capacity() const {
        return _capacity;
    }

    bool is_empty() const {
        return _size == 0;
    }

    void clear() {
        _size = 0;
    }

    T& peek() {
        return _data[_size - 1];
    }

    const T& peek() const {
        return _data[_size - 1];
    }
};

#endif

