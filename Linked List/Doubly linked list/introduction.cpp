#include<bits/stdc++.h>
using namespace std;
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = nullptr;
void create(int A[],int n){
    struct Node *t,*last;
    int i;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = nullptr;
    last = first;
    for(int i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
void display(struct Node *p){
    while(p){
        cout<<p->data<<" , ";
        p=p->next;
    }
    cout<<'\n';
}

//find the length of a linked list

int length(struct Node *p){
    int len = 0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

int main(){
    int A[]={5,4,3,2,1};
    create(A,5);
    display(first);
    cout<<length(first)<<'\n';
    return 0;
}