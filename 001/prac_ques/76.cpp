#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node * next;
    int data;
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node *prev = NULL;
        Node *h = head;
        while (h->next != NULL)
        {
            Node *next = h->next;
            h->next = prev;
            prev = h;
            h = next;
        }
        h->next = prev;
        Node *n = h;
        int a = h->data;
        while (h->next != NULL)
        {
            if (h->next->data < a)
            {
                h->next = h->next->next;
            }
            else
            {
                a = h->next->data;
                h = h->next;
            }
        }
        prev = NULL;
        while (n->next != NULL)
        {
            Node *next = n->next;
            n->next = prev;
            prev = n;
            n = next;
        }
        n->next = prev;
        return n;
    }
};
int main()
{

    return 0;
}