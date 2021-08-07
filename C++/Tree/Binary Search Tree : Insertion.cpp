#include<bits/stdc++.h>
using namespace std;

struct Tree{
       int data;
       Tree *parent;
       Tree *left;
       Tree *right;
};

Tree *createBST();
Tree *createNode(int data);
Tree *insertNodeInBST(Tree *root, Tree *newnode);
void addLeftChild(Tree *parent, Tree *child);
void addRightChild(Tree *parent, Tree *child);
void inOrderTraversing(Tree *root);

int main(void)
{
     int number;
     Tree *Root;
     Root = createBST();

     cout << Root->data << endl;

     inOrderTraversing(Root);

     return 0;
}

Tree *createBST()
{
    int number, data;
    Tree *newnode, *root;

    cout << "Number of node: ";
    cin >> number;

    cout << "Enter " << number << " Number: ";

    int i=1;
    while(i++ <= number)
    {
        cin >> data;
        newnode = createNode(data);
        root = insertNodeInBST(root, newnode);
    }

    return root;
}

Tree *createNode(int data)
{
    Tree *newnode = new Tree;

    newnode->data = data;
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

Tree *insertNodeInBST(Tree *root, Tree *newnode)
{
    Tree *parent, *current;
    if(root==NULL)
    {
        root = newnode;
        return root;
    }

    parent = NULL;
    current = root;

    while(current != NULL)
    {
        parent = current;
        if(current->data > newnode->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if(parent->data > newnode->data)
    {
        addLeftChild(parent, newnode);
    }
    else
    {
        addRightChild(parent, newnode);
    }

    return root;
}

void addLeftChild(Tree *parent, Tree *child)
{
    parent->left = child;
    child->parent = parent;
}

void addRightChild(Tree *parent, Tree *child)
{
    parent->right = child;
    child->parent = parent;
}

void inOrderTraversing(Tree *root)
{
    if(root->left!=NULL)
    {
        inOrderTraversing(root->left);
    }
    cout << root->data << " ";

    if(root->right!=NULL)
    {
        inOrderTraversing(root->right);
    }
}
