#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *left, *right;
    node(int data)
    {
        left = NULL;
        right = NULL;
        val = data;
    }
};
int main()
{
    vector<node *> v;
    node *n = new node(10);
    v.push_back(n);
    n = NULL;
    cout << v[0]->val << endl;  
    return 0;
}