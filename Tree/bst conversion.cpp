// C++ program to convert Binary Tree to Binary Search Tree 
#include <iostream>
#include <string>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void Store_In_Inorder(struct node *node, int inorder[], int *index_ptr)
{
    if (node == NULL)
    {
        return;
    }

    Store_In_Inorder(node->left, inorder, index_ptr);

    inorder[*index_ptr] = node->data;
    (*index_ptr)++;

    Store_In_Inorder(node->right, inorder, index_ptr);
}

int Count_Nodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return Count_Nodes(root->left) + Count_Nodes(root->right) + 1;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void Array_2_BST(int *arr, struct node *root, int *index_ptr)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    Array_2_BST(arr, root->left, index_ptr);

    root->data = arr[*index_ptr];
    (*index_ptr)++;

    Array_2_BST(arr, root->right, index_ptr);
}

void BT_2_BST(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    int n = Count_Nodes(root);
    int *arr = new int[n];

    int i = 0;
    Store_In_Inorder(root, arr, &i);
    qsort(arr, n, sizeof(arr[0]), compare);

    i = 0;
    Array_2_BST(arr, root, &i);
    delete[] arr;
}

struct node *newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void printInorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }

    printInorder(node->left);
    cout << " " << node->data;
    printInorder(node->right);
}

int main()
{
    struct node *root = NULL;

    /*
        10
        / \
        30 15
       / \
      20  5   */

    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    cout << "\n\t\tDate: " << __TIME__ << "\t\tTime: " << __DATE__ << endl
         << endl;

    BT_2_BST(root);
    cout << "Inorder Traversal of the converted BST: ";
    printInorder(root);
    cout << endl;
    cout << endl;

    return 0;
}