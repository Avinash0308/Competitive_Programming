#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *bottom;
    Node *next;
    int data;
};
Node *solve(Node *root)
{
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    Node *h = root;
    while (root->next != NULL)
    {
        Node *x = root->next;
        Node *ne = root->next->next;
        Node *t = root;
        while (x != NULL && t != NULL)
        {
            if (t->bottom == NULL)
            {
                t->bottom = x;
                break;
            }
            if (t->bottom->data < x->data)
            {
                t = t->bottom;
            }

            else
            {
                Node *n = x->bottom;
                Node *temp = t->bottom;
                t->bottom = x;
                t->bottom->bottom = temp;
                x = n;
                t = t->bottom;
            }
        }
        root->next = ne;
    }
    return root;
}
int main()
{

    return 0;
}