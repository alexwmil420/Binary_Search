#include <iostream>
using namespace std;

// Each node will store an integer as its data
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

void insertRecursive (BSTNode*& root, int value){
    if(!root){
        root = new BSTNode(value);
        return;
    }

    if(value < root->data) {
        insertRecursive(root->left, value);
    } 

    else if(value > root->data) {
        insertRecursive(root->right, value);
    }
}
void insertIterative(BSTNode*& root, int value) {
    if (!root) {
        root = new BSTNode(value);
        return;
    }

    // Set up a trailing pointer
    BSTNode* cur = root;
    BSTNode* parent = nullptr;

    while (cur) {
        parent = cur;
        if(value < cur->data) {
            cur = cur->left;
        } else if(value > cur->data) {
            cur = cur->right;
        } else {
            return; // duplicate so ignore
        }
    }
    if(value < parent->data) {
        parent->left = new BSTNode(value);
    } else {
        parent->right = new BSTNode(value);
    }
}

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

bool searchIterative(BSTNode* root, int key) {
    BSTNode* cur = root;
    while (cur) {
        if(key == cur->data) {
            return true;
        }
        if (key < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return false;
}
void inorderPrint(BSTNode* root) {
    if(!root) {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}
 // Free memory
    void freeTree(BSTNode* root) {
    			if(!root) {
        		return;
       }
    			freeTree(root->left);
    			freeTree(root->right);
    			delete root;
}

<<<<<<< HEAD
=======
int main() {
    BSTNode* root = nullptr;

    insertRecursive(root, 8);
    insertIterative(root, 3);
    insertIterative(root, 10);
    insertRecursive(root, 1);
    insertRecursive(root, 6);
    insertIterative(root, 14);
    insertRecursive(root, 4);
    insertIterative(root, 7);
    insertRecursive(root, 13);
    cout << "Inorder traversal: ";
    inorderPrint(root);
    cout << "\n";

    cout << "Search 7 (rec): " <<
        (searchRecursive(root,7)?"Found":"Not Found") << "\n";
    cout << "Search 9 (it): "  << 
        (searchIterative(root,9)?"Found":"Not Found") << "\n";

   // Always free dynamically allocated memory
    freeTree(root);

    return 0;
}

>>>>>>> testcode


