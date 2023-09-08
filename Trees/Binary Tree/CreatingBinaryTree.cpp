#include<iostream>
#include"Queue.h"
using namespace std;
struct Node *root = nullptr;

void Create(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("Enter root value");
    scanf("%d",&x);
    root=new Node();
    root->data = x;
    root->lchild= root->rchild=nullptr;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("Enter left child %d",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t= new Node();
            t->data =x;
            t->lchild = t->rchild =nullptr;
            p->lchild=t;
            enqueue(&q,t);
        }
        p=dequeue(&q);
        printf("Enter right child %d",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t= new Node();
            t->data =x;
            t->lchild = t->rchild =nullptr;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int main(){
    Create();
    preorder(root);
    return 0;
}