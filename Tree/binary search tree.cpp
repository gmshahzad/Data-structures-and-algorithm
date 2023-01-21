// C++ program to search a given key in binary search tree without recursion
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

bool search(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key > root->data)
        {
            root = root->right;
        }

        else if (key < root->data)
        {
            root = root->left;
        }

        else
        {
            return true;
        }
    }
    return false;
}

struct node *newNode(int item)
{
    struct node *temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int data)
{

    if (node == NULL)
    {
        return newNode(data);
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }

    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }

    return node;
}

int main()
{
    /*  BST
            50
            / \
        30	 70
        / \ / \
    20 40 60 80 */

    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "\n\t\tDate: " << __TIME__ << "\t\tTime: " << __DATE__ << endl
         << endl;

    if (search(root, 30))
    {
        cout << "Found! " << endl;
    }

    else
    {
        cout << "Not Found! " << endl;
    }
    cout << endl;
    return 0;
}