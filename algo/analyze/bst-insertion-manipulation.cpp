#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

typedef struct Node
{
    int key;
    Node *left;
    Node *right;
} Node;

Node *newNode(int key)
{
    Node *p = new Node;
    if (p == NULL)
        exit(0);

    p->key = key;
    p->left = NULL;
    p->right = NULL;

    return p;
}

Node *insert(Node *r, int key)
{
    if (r == NULL)
        return newNode(key);

    if (key > r->key)
    {
        r->right = insert(r->right, key);
    }
    else if (key < r->key)
    {
        r->left = insert(r->left, key);
    }
    return r;
}

void preOrder(Node *r)
{
    if (r == NULL)
        return;

    cout << r->key << " ";
    preOrder(r->left);
    preOrder(r->right);
}

void BST(string &input, Node **root)
{
    stringstream ss(input);
    string any;
    int key;
    ss >> any >> key;

    *root = insert(*root, key);
}

int main()
{
    Node *root = NULL;
    string inputString;

    while (getline(cin, inputString))
    {
        BST(inputString, &root);
        if (getchar() == '#')
            break;
    }

    preOrder(root);
    cout << endl;

    return 0;
}
