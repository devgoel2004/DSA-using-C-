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
int main(){
    int A[] = {3,5,7,10,15};
    Create(A,5);
    Display(first);
    cout<<"Max element is : "<<MaxElement(first);
    return 0;
}