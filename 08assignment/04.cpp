#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
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

    bool isBST(Node *root)
    {
        stack<Node *> st;
        Node *curr = root;
        long long prev = INT32_MIN;

        while (curr != nullptr || !st.empty())
        {
            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();

            if (curr->data <= prev)
                return false;
            prev = curr->data;

            curr = curr->right;
        }
        return true;
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

    if (t.isBST(t.root))
    {
        cout << "Tree is a BST" << endl;
    }
    else
    {
        cout << "Tree is not a BST" << endl;
    }
    return 0;
}
