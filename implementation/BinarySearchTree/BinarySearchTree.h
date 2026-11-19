
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* _root;
    int _size;

    Node* insert_recursive(Node* node, const T& value);
    Node* remove_recursive(Node* node, const T& value);
    Node* find_recursive(Node* node, const T& value) const;
    void clear_recursive(Node* node);
    int height_recursive(Node* node) const;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& other);
    BinarySearchTree& operator=(const BinarySearchTree& other);

    void insert(const T& value);
    void remove(const T& value);
    bool find(const T& value) const;

    void inorder() const;
    void preorder() const;
    void postorder() const;

    int size() const;
    int height() const;
    void clear();
    bool is_empty() const;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    _root = nullptr;
    _size = 0;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    clear();
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) {
    _root = nullptr;
    _size = other._size;

    auto copy = [](auto&& self, Node* node) -> Node* {
        if (node == nullptr) {
            return nullptr;
        }

        Node* newNode = new Node(node->data);
        newNode->left = self(self, node->left);
        newNode->right = self(self, node->right);

        return newNode;
    };

    _root = copy(copy, other._root);
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& other) {
    if (this == &other) {
        return *this;
    }

    clear();

    auto copy = [](auto&& self, Node* node) -> Node* {
        if (node == nullptr) {
            return nullptr;
        }

        Node* newNode = new Node(node->data);
        newNode->left = self(self, node->left);
        newNode->right = self(self, node->right);

        return newNode;
    };

    _root = copy(copy, other._root);
    _size = other._size;

    return *this;
}

template <typename T>
typename BinarySearchTree<T>::Node*
BinarySearchTree<T>::insert_recursive(Node* node, const T& value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insert_recursive(node->left, value);
    }
    else if (value > node->data) {
        node->right = insert_recursive(node->right, value);
    }

    return node;
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value) {
    if (find(value)) {
        return;
    }

    _root = insert_recursive(_root, value);
    _size++;
}

template <typename T>
typename BinarySearchTree<T>::Node*
BinarySearchTree<T>::find_recursive(Node* node, const T& value) const {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return find_recursive(node->left, value);
    }

    return find_recursive(node->right, value);
}

template <typename T>
bool BinarySearchTree<T>::find(const T& value) const {
    return find_recursive(_root, value) != nullptr;
}

template <typename T>
typename BinarySearchTree<T>::Node*
BinarySearchTree<T>::remove_recursive(Node* node, const T& value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = remove_recursive(node->left, value);
    }
    else if (value > node->data) {
        node->right = remove_recursive(node->right, value);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* successor = node->right;

        while (successor->left != nullptr) {
            successor = successor->left;
        }

        node->data = successor->data;
        node->right = remove_recursive(node->right, successor->data);
    }

    return node;
}

template <typename T>
void BinarySearchTree<T>::remove(const T& value) {
    if (!find(value)) {
        return;
    }

    _root = remove_recursive(_root, value);
    _size--;
}

template <typename T>
void BinarySearchTree<T>::clear_recursive(Node* node) {
    if (node == nullptr) {
        return;
    }

    clear_recursive(node->left);
    clear_recursive(node->right);

    delete node;
}

template <typename T>
void BinarySearchTree<T>::clear() {
    clear_recursive(_root);
    _root = nullptr;
    _size = 0;
}

template <typename T>
void BinarySearchTree<T>::inorder() const {
    auto traverse = [](auto&& self, Node* node) -> void {
        if (node == nullptr) {
            return;
        }

        self(self, node->left);
        std::cout << node->data << " ";
        self(self, node->right);
    };

    traverse(traverse, _root);
}

template <typename T>
void BinarySearchTree<T>::preorder() const {
    auto traverse = [](auto&& self, Node* node) -> void {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        self(self, node->left);
        self(self, node->right);
    };

    traverse(traverse, _root);
}

template <typename T>
void BinarySearchTree<T>::postorder() const {
    auto traverse = [](auto&& self, Node* node) -> void {
        if (node == nullptr) {
            return;
        }

        self(self, node->left);
        self(self, node->right);
        std::cout << node->data << " ";
    };

    traverse(traverse, _root);
}

template <typename T>
int BinarySearchTree<T>::size() const {
    return _size;
}

template <typename T>
int BinarySearchTree<T>::height_recursive(Node* node) const {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = height_recursive(node->left);
    int rightHeight = height_recursive(node->right);

    if (leftHeight > rightHeight) {
        return 1 + leftHeight;
    }

    return 1 + rightHeight;
}

template <typename T>
int BinarySearchTree<T>::height() const {
    return height_recursive(_root);
}

template <typename T>
bool BinarySearchTree<T>::is_empty() const {
    return _root == nullptr;
}

#endif
