#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Preorder traversal
void preorderTraversal(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    cout << node->data << " -> ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Postorder traversal
void postorderTraversal(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " -> ";
}

// Inorder traversal
void inorderTraversal(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    inorderTraversal(node->left);
    cout << node->data << " -> ";
    inorderTraversal(node->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);

    cout << "\n\t\tDate: " << __TIME__ << "\t\tTime: " << __DATE__ << endl
         << endl;

    cout << "\n\4 Inorder traversal ";
    inorderTraversal(root);
    cout << "NULL ";

    cout << "\n\4 Preorder traversal ";
    preorderTraversal(root);
    cout << "NULL ";

    cout << "\n\4 Postorder traversal ";
    postorderTraversal(root);
    cout << "NULL ";

    cout << endl
         << endl;
}
