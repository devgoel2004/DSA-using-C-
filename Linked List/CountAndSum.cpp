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

int count (struct Node *p){
    int cnt=0;
    while(p!=NULL){
        cnt++;
        p=p->next;
    }
    return cnt;
}

int Rcount(struct Node *p){
    if(p==NULL){
        return 0;
    }
    return Rcount(p->next)+1;
}

int sum(struct Node *p){
    int add=0;
    while(p!=NULL){
        add=add+p->data;
        p=p->next;
    }
    return add;
}
int main(){
    int A[] = {3,5,7,10,15};
    Create(A,5);
    Display(first);
    cout<<'\n';
    cout<<"Count is: "<<Rcount(first)<<'\n';
    cout<<"Sum is: "<<sum(first)<<'\n';
    return 0;
}