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
int main(){
    int A[] = {2,3,4,5,6};
    create(A,5);
    RecursiveDisplay(head);
    return 0;
}