#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*first;

void Create(int A[], int n){
    int i;
    struct Node *t,*last;

    first = new Node;
    first->data =A[0];
    first->next=NULL;
    last= first;
    for(i=1;i<n;i++){
        t=new Node;
        t->data= A[i];
        t->next=NULL;
        last->next =t;
        last=t;
    }
}

//Display function

void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int MaxElement(struct Node*p){
    int max=0;
    while(p!=NULL){
        if(p->data >max){
            max= p->data;
        }
        p=p->next;
    }
    return max;
}
int Count(struct Node *p){
    int l =0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}
void insert(struct Node *p ,int index, int x){
    struct Node *t,*temp;
    if(index<0 || index> Count(p)){
        return;
    }
    t=  new Node ;
    temp=new Node;
    if(index==0){
        t->data =x;
        t->next = first;
        first=t;
    }
    else{
        temp=first;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        t->data = x;
        t->next = temp->next;
        temp->next=t;
    }
}
void InsertSorted (struct Node *p,int x){
    struct Node *t, *q=NULL;
    t->data= x;
    t->next = NULL;
    if(first == NULL){
        first = t;
    }
    else{
        while(p && p->data <x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next = first;
            first=t;
        }
        else{
            t->next = q->next;
            q->next =t;
        }
    }
}
int count (struct Node *p){
    int cnt=0;
    while(p!=NULL){
        cnt++;
        p=p->next;
    }
    return cnt;
}

int Delete(struct Node *p, int index){
    struct Node *q=NULL;
    int x=-1;
    if(index<1|| index>count(p)){
        return -1;
    }
    if(index==1){
        q=first;
        x=first->data;
        first = first->next;
        delete q;
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x=p->data;
        delete p;
        return x;
    }
}
bool isSorted(struct Node *p){
    int x = INT_MIN;
    while(p!=NULL){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}
int main(){
    int A[] = {3,2,7,10,15};
    Create(A,5);
    Display(first);
    if(isSorted(first)){
        cout<<"YES\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}