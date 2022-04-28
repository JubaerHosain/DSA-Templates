#include <bits/stdc++.h>
using namespace std;

struct node{
       int data;
       node *parent;
       node *left;
       node *right;
};
node *createBST(int number);
node *createNode(int data);
node *insertNode(node *root, node *newnode);
void addLeftNode(node *parent, node *child);
void addRightNode(node *parent, node *child);
node *BSTsearch(node *root, int data);

int main(void)
{
       node *root, *searchNode;
       int number, data;

       cout << "\t\t\t  :::::::: " << "WELCOME TO TREE" << " ::::::::" << endl;
       cout << "\t\t\t ===================================" << endl;

       cout << "Enter the number of element: ";
       cin >> number;

       root = createBST(number);

       cout << root->data << endl;

       cout << "Enter a number for search: ";
       cin >> data;
       searchNode = BSTsearch(root, data);

       if(searchNode != NULL)
       {
           cout << searchNode->data << " is found." << endl;
       }
       else
       {
           cout << data << " is not found." << endl;
       }

       return 0;
}

node *createBST(int number)
{
      node *newnode, *root = NULL;
      int i=1, data;

      cout << "Enter " << number << " element(using space): ";

      while(i++ <= number)
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
          cout << "\aError! Could not create node." << endl;
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
          if(newnode->data < current->data)
          {
              current = current->left;
          }
          else
          {
              current = current->right;
          }
      }

      if(newnode->data < parent->data)
      {
          addLeftNode(parent, newnode);
      }
      else
      {
          addRightNode(parent, newnode);
      }

      return root;
}

void addLeftNode(node *parent, node *child)
{
     parent->left = child;
     child->parent = parent;
}

void addRightNode(node *parent, node *child)
{
     parent->right = child;
     child->parent = parent;
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
