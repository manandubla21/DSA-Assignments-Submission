#include <iostream>
#include <string>
using namespace std;

class Node{
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

    void searchRecursive(Node* node, int val, int level) {
        if (node == NULL) {
            return;
        }

        if (node->data == val) {
            cout << "Node found at level " << level << endl;
            return;
        }

        searchRecursive(node->left, val, level + 1);
        searchRecursive(node->right, val, level + 1);
    }


    void searchIterative(Node* node , int val) {
        int count = 1;
        while(node != NULL) {
            if(node->data == val) {
                cout << "Node found at level " << count << endl;
                return;
            } else if(node->data > val) {
                node = node->left;
                count++;
            } else if(node->data < val) {
                node = node->right;
                count++;
            }
        }
    }

    
    int maxElement(Node* node) {
        while(node->right != NULL) {
            node = node->right;
        }
        return node->data;
    }
    
    int minElement(Node* node) {
        while(node->left != NULL) {
            node = node->left;
        }
        return node->data;
    }

    Node* successor(Node* node) {
        node = node->right;
        Node* temp = new Node(minElement(node));
        return temp;
    }

    Node* predecessor(Node* node) {
        node = node->left;
        Node* temp = new Node(maxElement(node));
        return temp;
    }

};

int main() {
    Tree t;
    t.root = new Node(4);
    t.root->left = new Node(2);
    t.root->right = new Node(5);
    t.root->left->left = new Node(1);
    t.root->left->right = new Node(3);

    t.searchRecursive(t.root, 5 , 1);
    t.searchIterative(t.root, 3);

    cout << "Maximum element of BST is : " << t.maxElement(t.root) << endl;
    cout << "Minimum element of BST is : " << t.minElement(t.root) << endl;

    cout << "Successor of BST is : " << (t.successor(t.root))->data << endl;
    cout << "Predecessor of BST is : " << (t.predecessor(t.root))->data<< endl;
    return 0;
}