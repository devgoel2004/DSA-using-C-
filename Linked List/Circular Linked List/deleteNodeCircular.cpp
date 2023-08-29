#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*head;

void create(int A[], int n){
    int i;
    struct Node *t,*last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;
    for(i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *h){
    do{
        cout<<h->data<<" ";
        h=h->next;
    }
    while(h!=head);
    cout<<'\n';
}
void RecursiveDisplay (struct Node *h){
    static int flag=0;
    if(h!=head || flag==0){
        flag=1;
        cout<<h->data<<' ';
        RecursiveDisplay(h->next);
    }
    //cout<<'\n';
    flag=0;
}

//insert function in circular linked list

void Insert(struct Node *p, int index, int x){
    struct Node *t,*temp;
    int i;

    if(index==0){
        t=new Node;
        t->data = x;
        if(p==NULL){
            p=t;
            p->next = p;
        }
        else{
            temp=p;
            while(temp->next != p){
                p=p->next;
            }
            temp->next =t;
            t->next = p;
            p=t;
        }
        
    }
    else{
            temp= p;
            for(i=0;i<index-1;i++){
                temp=temp->next;
            }
            t=new Node;
            t->data = x;
            t->next = temp->next;
            temp->next= t;
        }
}
int Delete(struct Node *p, int index){
    struct Node *q;
    int i,x;
    if(index==0){
        while(p->next!=head){
            p=p->next;
        }
         x = head->data;
        if(head==p){
            free(head);
            head = nullptr;
        }
        else{
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else{
        for(i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next =q->next;
         x=q->data;
        free(q);
    }
    return x;
}
int main(){
    int A[] = {2,3,4,5,6};
    create(A,5);
    Delete(head,0);
    RecursiveDisplay(head);
    return 0;
}