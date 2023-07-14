#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
	Node * prev;
};
Node* sortedInsert(Node * head, int x)
{
	// Code here
	Node * n = new Node;
	n->data = x;
	if(x < head->data){
	   n->prev = NULL;
	   n->next = head;
	   head = n;
	   return n;
	}
	Node * f = head;
	while(x < f->next->data && f!= NULL){
	    f = f->next;
	}
	n->prev = f;
	n->next = f->next;
	f->next = n;
	n->next->prev = f;
	return head;
}
int main(){
    
return 0;
}