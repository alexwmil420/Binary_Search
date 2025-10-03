#include <iostream>
using namespace std;


struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

bool searchRecursive(BSTNode* root, int key) {
    if(!root) {
        return false;
    }
    if(root->data == key) {
        return true;
    }
    if(key < root->data) {
        return searchRecursive(root->left, key);
    } else {
        return searchRecursive(root->right, key);
    }
}
