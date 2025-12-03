#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

class Tree
{
public:
    Node *root;

    Tree()
    {
        root = NULL;
    }

    void insertEle(int val)
    {
        if (root == nullptr)
        {
            root = new Node(val);
            return;
        }

        Node *node = root;
        Node *parent = nullptr;

        while (node != nullptr)
        {
            parent = node;
            if (val < node->data)
                node = node->left;
            else if (val > node->data)
                node = node->right;
            else
                return;
        }

        if (val < parent->data)
            parent->left = new Node(val);
        else
            parent->right = new Node(val);
    }

    Node *minValueNode(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        Node *curr = node;
        while (curr->left != nullptr)
            curr = curr->left;
        return curr;
    }

    Node *deleteNode(Node *node, int key)
    {
        if (node == nullptr)
            return nullptr;

        if (key < node->data)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = deleteNode(node->right, key);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            // case: only left child
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node *succ = minValueNode(node->right);
                node->data = succ->data;
                node->right = deleteNode(node->right, succ->data);
            }
        }
        return node;
    }

    void inOrder(Node *node)
    {
        if (node == nullptr)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    int maxDepth(Node *node)
    {
        if (node == NULL)
            return 0;

        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        int totalDepth = 1 + max(leftDepth, rightDepth);

        return totalDepth;
    }

    int minDepth(Node *node)
    {
        if (node == NULL)
            return 0;

        if (node->left == NULL)
            return 1 + minDepth(node->right);

        if (node->right == NULL)
            return 1 + minDepth(node->left);

        return 1 + min(minDepth(node->left), minDepth(node->right));
    }
};

int main()
{
    Tree t;
    t.root = new Node(4);
    t.root->left = new Node(2);
    t.root->right = new Node(7);
    t.root->left->left = new Node(1);
    t.root->left->right = new Node(3);

    cout << "Before : ";
    t.inOrder(t.root);
    cout << endl;

    t.insertEle(6);
    t.insertEle(5);

    t.root = t.deleteNode(t.root, 4);

    cout << "After  : ";
    t.inOrder(t.root);
    cout << endl;

    cout << "Max depth of BST : " << t.maxDepth(t.root) << endl;
    cout << "Min depth of BST : " << t.minDepth(t.root) << endl;
    cout << "Min depth of node : " << t.minDepth(t.root->right) << endl;
    return 0;
}
