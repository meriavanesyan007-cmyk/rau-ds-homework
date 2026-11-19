#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findMax(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int maxVal = root->data;

    if (root->left != nullptr) {
        int leftMax = findMax(root->left);

        if (leftMax > maxVal) {
            maxVal = leftMax;
        }
    }

    if (root->right != nullptr) {
        int rightMax = findMax(root->right);

        if (rightMax > maxVal) {
            maxVal = rightMax;
        }
    }

    return maxVal;
}

int findMin(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int minVal = root->data;

    if (root->left != nullptr) {
        int leftMin = findMin(root->left);

        if (leftMin < minVal) {
            minVal = leftMin;
        }
    }

    if (root->right != nullptr) {
        int rightMin = findMin(root->right);

        if (rightMin < minVal) {
            minVal = rightMin;
        }
    }

    return minVal;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);

    int maxVal = findMax(root);
    int minVal = findMin(root);

    std::cout << "Max: " << maxVal << "\n";
    std::cout << "Min: " << minVal;

    return 0;
}
