#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100
struct Node{
       char data;
       int frequency;
       Node *Left, *Right;
};
Node **HeapArray;
int HeapSize;

void HuffmanCoding(char Array[], int frequency[], int Size);
Node *CreateHuffmanTree(char Array[], int frequency[], int Size);
Node *CreateNode(char data, int frequency);
void BuildMinHeap();
void MinHeapify(int parent);
Node *ExtractMinHeap();
void InsertMinHeap(Node *top);
void PrintHuffmanCode(Node *Root, int code[], int top);
void Swap(Node **node1, Node **node2);
void PrintCode(int code[], int n);

int main(void)
{
    char *Array;
    int *frequency;

    cout << "Enter Number of Distinct Character: ";
    cin >> HeapSize;
    Array = new char[HeapSize];
    frequency = new int[HeapSize];

    cout << "Enter " << HeapSize << " Pair[Character,Frequency](Use Space Between a Character & Frequency): " << endl;
    for(int i=0; i<HeapSize; i++)
    {
        cin >> Array[i] >> frequency[i];
    }

    HuffmanCoding(Array, frequency, HeapSize);


}

void HuffmanCoding(char Array[], int frequency[], int Size)
{
    Node *Root = CreateHuffmanTree(Array, frequency, Size);

    int code[MAX_HEIGHT], top=0;

    cout << "Huffman Code For Each Character: " << endl;
    PrintHuffmanCode(Root, code, top);
}

Node *CreateHuffmanTree(char Array[], int frequency[], int Size)
{
    Node *left, *right, *newnode;
    //createHeapArray
    HeapArray = new Node*[HeapSize+1];

    for(int i=0;  i<HeapSize;  i++)
    {
        HeapArray[i+1] = CreateNode(Array[i], frequency[i]);
    }

    //build min-heap
    BuildMinHeap();


     while(HeapSize != 1)
     {
        left = ExtractMinHeap();
        right= ExtractMinHeap();

        newnode = new Node;
        newnode->data = '#';
        newnode->frequency = left->frequency + right->frequency;
        newnode->Left = left;
        newnode->Right = right;

        InsertMinHeap(newnode);
     }

     return ExtractMinHeap();
}

Node *CreateNode(char data, int frequency)
{
    Node *newnode = new Node;

    newnode->data = data;
    newnode->frequency = frequency;
    newnode->Left = NULL;
    newnode->Right = NULL;

    return newnode;
}

void BuildMinHeap()
{
    for(int parent=HeapSize/2;  parent>=1; parent--)
    {
        MinHeapify(parent);
    }
}


void MinHeapify(int parent)
{
    int leftIndex, rightIndex, smallIndex;
    leftIndex = 2 * parent;
    rightIndex = 2 * parent + 1;

    if(leftIndex <= HeapSize && HeapArray[leftIndex]->frequency < HeapArray[parent]->frequency)
    {
        smallIndex = leftIndex;
    }
    else
    {
        smallIndex = parent;
    }

    if(rightIndex <= HeapSize && HeapArray[rightIndex]->frequency < HeapArray[smallIndex]->frequency)
    {
        smallIndex = rightIndex;
    }

    if(smallIndex != parent)
    {
        Swap(&HeapArray[parent], &HeapArray[smallIndex]);

        MinHeapify(smallIndex);
    }
}

void Swap(Node **node1, Node **node2)
{
    Node *temp;

    temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

Node *ExtractMinHeap()
{
    Node *temp = HeapArray[1];

    Swap(&HeapArray[1], &HeapArray[HeapSize]);

    HeapSize = HeapSize-1;
    MinHeapify(1);

    return temp;
}

void InsertMinHeap(Node *top)
{
    HeapSize = HeapSize + 1;
    HeapArray[HeapSize] = top;

    int parent = 0;
    int location = HeapSize;


    while (location > 1)
    {
         parent = location / 2;

         if(HeapArray[parent]->frequency > HeapArray[location]->frequency)
         {
            Swap(&HeapArray[parent], &HeapArray[location]);

            location = parent;
         }
         else
         {
            return;
         }
    }
}

void PrintHuffmanCode(Node *Root,  int code[], int top)
{
    if(Root->Left)
    {
        code[top] = 0;
        PrintHuffmanCode(Root->Left, code, top + 1);
    }

    if(Root->Right)
    {
        code[top] = 1;
        PrintHuffmanCode(Root->Right, code, top + 1);
    }

    if( !(Root->Left) && !(Root->Right) )
    {
        cout << Root->data << ": ";
        PrintCode(code, top);
    }
}

void PrintCode(int code[], int n)
{
    int i;
    for(i=0;  i<n; i++)
    {
        cout << code[i];
    }

    cout << endl;
}
