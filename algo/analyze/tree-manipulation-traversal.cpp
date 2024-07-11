#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

typedef struct Node
{
    int id;
    Node *leftMostChild;
    Node *rightSibling;
} Node;

Node *newNode(int id)
{
    Node *p = new Node;
    if (p == NULL)
    {
        exit(0);
    }
    p->id = id;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;

    return p;
}

Node *find(Node *r, int id)
{
    if (r == NULL)
        return NULL;
    if (r->id == id)
        return r;

    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        Node *hv = find(p, id);
        if (hv != NULL)
            return hv;
        p = p->rightSibling;
    }

    return NULL;
}

Node *findLast(Node *r)
{
    Node *pp;

    if (r == NULL)
        return NULL;

    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        findLast(p);
        pp = p;
        p = p->rightSibling;
    }

    return pp;
}

Node *Insert(Node *u, Node *r)
{
    if (r == NULL)
        return NULL;
    if (find(r, u->id) != NULL)
        return r;

    Node *p = r->leftMostChild;
    if (p == NULL)
        r->leftMostChild = u;
    else
    {
        while (p->rightSibling != NULL)
        {
            p = p->rightSibling;
        }
        p->rightSibling = u;
    }
    return r;
}

void preOrder(Node *r)
{
    if (r == NULL)
        return;

    cout << r->id << " ";

    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        preOrder(p);
        p = p->rightSibling;
    }
}

void postOrder(Node *r)
{
    if (r == NULL)
        return;

    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        postOrder(p);
        p = p->rightSibling;
    }

    cout << r->id << " ";
}

void inOrder(Node *r)
{
    if (r == NULL)
        return;

    Node *p = r->leftMostChild;
    inOrder(p);

    cout << r->id << " ";

    if (p != NULL)
        p = p->rightSibling;
    while (p != NULL)
    {
        inOrder(p);
        p = p->rightSibling;
    }
}

void TreeManipulation(string &input, Node **root)
{
    stringstream ss(input);
    string any;
    int x1, x2;
    ss >> any >> x1 >> x2;

    if (any == "MakeRoot")
    {
        *root = newNode(x1);
    }
    else if (any == "Insert")
    {
        Insert(newNode(x1), find(*root, x2));
    }
    else if (any == "PreOrder")
    {
        preOrder(*root);
        cout << endl;
    }
    else if (any == "InOrder")
    {
        inOrder(*root);
        cout << endl;
    }
    else if (any == "PostOrder")
    {
        postOrder(*root);
        cout << endl;
    }
}

int main()
{
    Node *root;
    string inputString;

    while (getline(cin, inputString))
    {
        TreeManipulation(inputString, &root);
        if (inputString == "*")
            break;
    }

    return 0;
}
