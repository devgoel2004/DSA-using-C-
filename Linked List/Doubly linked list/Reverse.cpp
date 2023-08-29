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
//insert node in doubly linked list

void insert(struct Node *p, int x, int index){
    if(index == 0){
        struct Node *t;
        t=new Node;
        t->data =x ;
        t->prev = nullptr;
        t->next =first;
        first->prev = t;
        first = t;
    }
    else{
        struct Node *t;
        t= new Node;
        t->data = x;
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->prev = p;
        t->next =p->next;
        if(p->next){
            p->next->prev = t;
        }
        p->next =t;
    }
}
void Reverse(struct Node *p){
    struct Node *temp;
    while(p!=NULL){
        temp=p->next;
        p->next= p->prev;
        p->prev= temp;
        p=p->prev;
        if(p!=NULL && p->next == NULL){
            first = p;
        }
    }
}
int main(){
    int A[]={5,4,3,2,1};
    create(A,5);
    insert(first,10,2);
    //display(first);
    Reverse(first);
    display(first);
    cout<<length(first)<<'\n';
    return 0;
}