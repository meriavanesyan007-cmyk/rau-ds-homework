
#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>
#include <sstream>

void fillTree(BinarySearchTree<int>& bst) {
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
}

void test_insert() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    assert(bst.size() == 1);
    assert(bst.find(50));

    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    assert(bst.size() == 5);
    assert(bst.find(30));
    assert(bst.find(70));

    bst.insert(50);
    assert(bst.size() == 5);

    std::cout << "test_insert passed\n";
}

void test_remove() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.remove(20);
    assert(!bst.find(20));
    assert(bst.size() == 6);

    bst.remove(30);
    assert(!bst.find(30));
    assert(bst.find(40));
    assert(bst.size() == 5);

    bst.remove(70);
    assert(!bst.find(70));
    assert(bst.find(60));
    assert(bst.find(80));
    assert(bst.size() == 4);

    bst.remove(50);
    assert(!bst.find(50));
    assert(bst.size() == 3);

    bst.remove(100);
    assert(bst.size() == 3);

    std::cout << "test_remove passed\n";
}

void test_find() {
    BinarySearchTree<int> bst;

    assert(!bst.find(10));

    bst.insert(10);
    bst.insert(20);

    assert(bst.find(10));
    assert(bst.find(20));
    assert(!bst.find(30));

    std::cout << "test_find passed\n";
}

void test_inorder() {
    BinarySearchTree<int> bst;
    fillTree(bst);

    std::ostringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    bst.inorder();

    std::cout.rdbuf(old);

    assert(output.str() == "20 30 40 50 70 ");

    std::cout << "test_inorder passed\n";
}

void test_preorder() {
    BinarySearchTree<int> bst;
    fillTree(bst);

    std::ostringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    bst.preorder();

    std::cout.rdbuf(old);

    assert(output.str() == "50 30 20 40 70 ");

    std::cout << "test_preorder passed\n";
}

void test_postorder() {
    BinarySearchTree<int> bst;
    fillTree(bst);

    std::ostringstream output;
    std::streambuf* old = std::cout.rdbuf(std::cout.rdbuf(output.rdbuf()));

    bst.postorder();

    std::cout.rdbuf(old);

    assert(output.str() == "20 40 30 70 50 ");

    std::cout << "test_postorder passed\n";
}

void test_size() {
    BinarySearchTree<int> bst;

    assert(bst.size() == 0);

    bst.insert(10);
    assert(bst.size() == 1);

    bst.insert(20);
    assert(bst.size() == 2);

    bst.remove(10);
    assert(bst.size() == 1);

    std::cout << "test_size passed\n";
}

void test_height() {
    BinarySearchTree<int> bst;

    assert(bst.height() == 0);

    bst.insert(50);
    assert(bst.height() == 1);

    bst.insert(30);
    bst.insert(70);
    bst.insert(20);

    assert(bst.height() == 3);

    std::cout << "test_height passed\n";
}

void test_clear() {
    BinarySearchTree<int> bst;
    fillTree(bst);

    bst.clear();

    assert(bst.size() == 0);
    assert(bst.is_empty());
    assert(!bst.find(50));
    assert(bst.height() == 0);

    std::cout << "test_clear passed\n";
}

void test_is_empty() {
    BinarySearchTree<int> bst;

    assert(bst.is_empty());

    bst.insert(10);
    assert(!bst.is_empty());

    bst.remove(10);
    assert(bst.is_empty());

    std::cout << "test_is_empty passed\n";
}

void test_copy_constructor() {
    BinarySearchTree<int> bst;
    fillTree(bst);

    BinarySearchTree<int> copy(bst);

    assert(copy.size() == 5);
    assert(copy.find(50));
    assert(copy.find(20));

    copy.insert(100);

    assert(copy.size() == 6);
    assert(bst.size() == 5);
    assert(!bst.find(100));

    std::cout << "test_copy_constructor passed\n";
}

void test_assignment_operator() {
    BinarySearchTree<int> bst;
    fillTree(bst);

    BinarySearchTree<int> copy;
    copy.insert(999);

    copy = bst;

    assert(copy.size() == 5);
    assert(copy.find(50));
    assert(!copy.find(999));

    copy.remove(50);

    assert(bst.find(50));
    assert(!copy.find(50));

    bst = bst;
    assert(bst.size() == 5);

    std::cout << "test_assignment_operator passed\n";
}

int main() {
    std::cout << "Running BinarySearchTree tests\n\n";

    test_insert();
    test_remove();
    test_find();
    test_inorder();
    test_preorder();
    test_postorder();
    test_size();
    test_height();
    test_clear();
    test_is_empty();
    test_copy_constructor();
    test_assignment_operator();

    std::cout << "\nAll tests passed!\n";

    return 0;
}
