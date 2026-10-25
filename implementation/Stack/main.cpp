
#include "Stack.h"
#include <cassert>
#include <iostream>

void test_push() {
    Stack<int> s;

    s.push(5);
    assert(s.size() == 1);
    assert(s.top() == 5);

    s.push(10);
    s.push(15);
    assert(s.size() == 3);
    assert(s.top() == 15);

    std::cout << "test_push passed" << std::endl;
}

void test_pop() {
    Stack<int> s;
    s.push(5);
    s.push(10);

    s.pop();
    assert(s.size() == 1);
    assert(s.top() == 5);

    s.pop();
    assert(s.is_empty());

    std::cout << "test_pop passed" << std::endl;
}

void test_top_and_peek() {
    Stack<int> s;
    s.push(20);
    s.push(30);

    assert(s.top() == 30);
    assert(s.peek() == 30);
    assert(s.size() == 2);

    std::cout << "test_top_and_peek passed" << std::endl;
}

void test_size_and_capacity() {
    Stack<int> s;

    assert(s.size() == 0);
    assert(s.capacity() >= 1);

    int oldCapacity = s.capacity();

    for (int i = 0; i < oldCapacity + 1; i++) {
        s.push(i);
    }

    assert(s.size() == oldCapacity + 1);
    assert(s.capacity() > oldCapacity);

    std::cout << "test_size_and_capacity passed" << std::endl;
}

void test_is_empty_and_clear() {
    Stack<int> s;

    assert(s.is_empty());

    s.push(1);
    s.push(2);
    assert(!s.is_empty());

    s.clear();
    assert(s.is_empty());
    assert(s.size() == 0);

    std::cout << "test_is_empty_and_clear passed" << std::endl;
}

void test_copy_constructor() {
    Stack<int> s;
    s.push(5);
    s.push(10);

    Stack<int> copy(s);

    assert(copy.size() == 2);
    assert(copy.top() == 10);

    copy.push(15);
    assert(copy.size() == 3);
    assert(s.size() == 2);

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment() {
    Stack<int> s;
    s.push(7);
    s.push(14);

    Stack<int> copy;
    copy.push(100);
    copy = s;

    assert(copy.size() == 2);
    assert(copy.top() == 14);

    copy.pop();
    assert(copy.top() == 7);
    assert(s.top() == 14);

    std::cout << "test_assignment passed" << std::endl;
}

int main() {
    std::cout << "Running Stack tests" << std::endl;

    test_push();
    test_pop();
    test_top_and_peek();
    test_size_and_capacity();
    test_is_empty_and_clear();
    test_copy_constructor();
    test_assignment();

    std::cout << "All tests passed" << std::endl;
    return 0;
}

