// C++ program to check a given binary tree is BST or NOT
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

struct n
{
    int d;
    n *left;
    n *right;
};

int BSTUtil(n *node, int min, int max);

int isBST(n *node)

{
    return (BSTUtil(node, INT_MIN, INT_MAX));
}

int BSTUtil(struct n *node, int min, int max)
{
    if (node == NULL)
    {
        return 1;
    }

    if (node->d < min || node->d > max)
    {
        return 0;
    }
    return BSTUtil(node->left, min, node->d - 1) &&
           BSTUtil(node->right, node->d + 1, max);
}

n *newN(int d)
{
    n *node = new n;
    node->d = d;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    n *root = newN(7);
    root->left = newN(6);
    root->right = newN(10);
    root->left->left = newN(2);
    root->left->right = newN(4);

    cout << "\n\t\tDate: " << __TIME__ << "\t\tTime: " << __DATE__ << endl
         << endl;
    cout << endl;
    if (isBST(root))
    {
        cout << "\4 The Given Binary Tree is a BST" << endl;
    }

    else
    {
        cout << "\4 The Given Binary Tree is not a BST" << endl;
    }

    n *root1 = newN(10);
    root1->left = newN(6);
    root1->right = newN(11);
    root1->left->left = newN(2);
    root1->left->right = newN(7);

    cout << endl;
    if (isBST(root1))
    {
        cout << "\4 The Given Binary Tree is a BST" << endl;
    }

    else
    {
        cout << "\4 The Given Binary Tree is not a BST" << endl;
    }
    cout << endl;

    return 0;
}