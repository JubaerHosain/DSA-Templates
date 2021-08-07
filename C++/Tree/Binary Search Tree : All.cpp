#include<bits/stdc++.h>
using namespace std;

struct node{
       int data;
       node *parent;
       node *left;
       node *right;
};

void TreeMenu();
void traverseMenu(node *root);
node *createNode(int data);
node *createBST();
node *insertNode(node *root, node *newnode);
node *BSTsearch(node *root, int data);
node *BSTsuccessor(node *root);
node *BSTdelete(node *root, node *deletenode);
node *BSTtransplant(node *root, node *current, node *newnode);
void addLeftChild(node *parent, node *child);
void addRightChild(node *parent, node *child);
void preOrderTraversing(node *root);
void inOrderTraversing(node *root);
void postOrderTraversing(node *root);

int main(void)
{
    TreeMenu();
    return 0;
}

void TreeMenu()
{
    node *Root = createBST();
    cout << "BST Created Successfully.";

    node *newnode;
    int choice, data;

    do
    {
        cout << endl << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Node" << endl;
        cout << "4. Traverse Node" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
           case 1:
               cout << "Enter data for this node: ";
               cin >> data;
               newnode = createNode(data);
               Root = insertNode(Root, newnode);
               cout << data << " is inserted successfully.\n";
               break;

           case 2:
               cout << "Enter data for delete: ";
               cin >> data;
               newnode = BSTsearch(Root, data);
               if(newnode != NULL)
               {
                   Root = BSTdelete(Root, newnode);
                   cout << data << " is deleted successfully.\n";
               }
               else
               {
                   cout << "Data is not found in the tree.\n";
               }
               break;

           case 3:
                cout << "Enter data for search: ";
                cin >> data;
                newnode = BSTsearch(Root, data);
                if(newnode != NULL)
                {
                    cout << "Data is found in the tree.\n";
                }
                else
                {
                    cout << "Data is not found in the tree.\n" ;
                }
                break;

           case 4:
               if(Root == NULL)
               {
                   cout << "Tree is empty! \n";
               }
               else
               {
                  traverseMenu(Root);
               }
               break;

           case 0: exit(1);

           default: cout << "Wrong input! Try Again.\n";
        }

    }while(1);
}

void traverseMenu(node *root)
{
    int choice;
    cout << endl << endl;
    cout << "1. PreOrder Traversing" << endl;
    cout << "2. InOrder Traversing" << endl;
    cout << "3. PostOrder Traversing" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        cout << "PreOrder: ";
        preOrderTraversing(root);
        break;

        case 2:
        cout << "InOrder: ";
        inOrderTraversing(root);
        break;

        case 3:
        cout << "PostOrder: ";
        postOrderTraversing(root);
        break;

        default : cout << "Wrong Input!\n";
    }

}

node *createBST()
{
    int nodeNo, data;
    node *newnode, *root= NULL;
    cout << "How many node you want to create: ";
    cin >> nodeNo;
    cout << "Enter " << nodeNo << " element: ";

    while(nodeNo-- >= 1)
    {
        cin >> data;

        newnode = createNode(data);
        root = insertNode(root, newnode);
    }

    return root;
}

node *createNode(int data)
{
    node *newnode = new node;
    if(newnode == NULL)
    {
        cout << "Error! Could not create newnode\n";
        exit(1);
    }

    newnode->data = data;
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

node *insertNode(node *root, node *newnode)
{
    node *parent, *current;

    if(root == NULL)
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

void addLeftChild(node *parent, node *child)
{
    parent->left = child;

    if(child !=NULL)
    {
       child->parent = parent;
    }
}

void addRightChild(node *parent, node *child)
{
    parent->right = child;

    if(child != NULL)
    {
        child->parent = parent;
    }
}

void preOrderTraversing(node *root)
{
    cout << root->data << " ";

    if(root->left != NULL)
    {
        preOrderTraversing(root->left);
    }

    if(root->right != NULL)
    {
        preOrderTraversing(root->right);
    }
}

void inOrderTraversing(node *root)
{
    if(root->left != NULL)
    {
        inOrderTraversing(root->left);
    }

    cout << root->data << " ";

    if(root->right != NULL)
    {
        inOrderTraversing(root->right);
    }
}

void postOrderTraversing(node *root)
{
    if(root->left != NULL)
    {
        postOrderTraversing(root->left);
    }


    if(root->right != NULL)
    {
        postOrderTraversing(root->right);
    }

    cout << root->data << " ";
}

node *BSTsearch(node *root, int data)
{
     node *current = root;

     while(current != NULL)
     {
         if(current->data ==  data)
         {
              return current;
         }

         if(data < current->data)
         {
             current = current->left;
         }
         else
         {
             current = current->right;
         }
     }

     return current;
}

node *BSTdelete(node *root, node *deleteNode)
{
     node *successor;

     if(deleteNode->left == NULL)
     {
         root = BSTtransplant(root, deleteNode, deleteNode->right);
     }
     else if(deleteNode->right == NULL)
     {
         root = BSTtransplant(root, deleteNode, deleteNode->left);
     }
     else
     {
         successor = BSTsuccessor(deleteNode->right);

         if(successor->parent != deleteNode)
         {
             root = BSTtransplant(root, successor, successor->right);
             addRightChild(successor, deleteNode->right);
         }
         root = BSTtransplant(root, deleteNode, successor);
         addLeftChild(successor, deleteNode->left);
     }

     free(deleteNode);

     return root;
}

node *BSTtransplant(node *root, node *current, node *newnode)
{
    if(current == root)
    {
        root = newnode;
    }
    else if(current == current->parent->left)
    {
        addLeftChild(current->parent, newnode);
    }
    else
    {
        addRightChild(current->parent, newnode);
    }

    return root;
}


node *BSTsuccessor(node *root)
{
    node *successor = root;

    while(successor->left != NULL)
    {
        successor = successor->left;
    }

    return successor;
}
