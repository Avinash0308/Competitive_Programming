#include<bits/stdc++.h>
using namespace std;

struct tree{
    int x;
    struct tree* l;
    struct tree* r;
};

void display(struct tree* t){
    if(t == NULL) return;
    display(t->l);
    cout<<t->x<<" ";
    display(t->r);
}

struct tree* solution(struct tree* t){
    if(!t) return NULL;
    if(!(t->l) && !(t->r)){
        t->l = new tree();
        t->r = new tree();
        t->l->x = t->x;
        t->r->x = t->x;
        t->l->l = t->l->r = t->r->l = t->r->r = NULL;
        return t;
    }
    t->l = solution(t->l);
    t->r = solution(t->r);
    return t;
}

int main(){
    struct tree* t = new tree();
    t->x = 1;
    t->l = new tree();
    t->l->x = 2;
    t->r = new tree();
    t->r->x = 3;
    display(t);
    cout<<endl;
    t = solution(t);
    display(t);
    return 0;
}