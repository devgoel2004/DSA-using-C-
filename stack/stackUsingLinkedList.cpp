#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*top = nullptr;

void push(int x){
    struct Node *t;
    t= new Node();
    // t->data=x;
    if(t==nullptr){
        printf("Stack is full");
    }
    else{
        t->data = x;
        t->next = top;
        top= t;
    }
}

int pop(){
    struct Node *t;
    int x=-1;
    if(top==nullptr){
        printf("Stack is Empty\n");
    }
    else{
        t=top;
        top = top->next;
        x= t->data;
        free(t);
    }
    return x;
}

void display(){
    struct Node *p;
    p = top;
    while(p!=nullptr){
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<'\n';
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    printf("%d",pop());
    return 0;
}