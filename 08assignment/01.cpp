#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node* root;

    Tree() { 
        root = NULL;
    }

    void preOrder(Node* node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node* node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    Tree t;
    t.root = new Node(4);
    t.root->left = new Node(2);
    t.root->right = new Node(5);
    t.root->left->left = new Node(1);
    t.root->left->right = new Node(3);

    t.preOrder(t.root);
    cout << endl;
    
    t.inOrder(t.root);
    cout << endl;

    t.postOrder(t.root);
    cout << endl;
    return 0;
}