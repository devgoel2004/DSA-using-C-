#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct Node{
    char data;
    struct Node *next;
}*top = NULL;

void push(char x){
    struct Node *t;
    t = new Node;
    if(t==nullptr){
        cout<<"Stack is full\n";
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop(){
    struct Node *t;
    char x='\n';
    if(top==nullptr){
        printf("Stack is empty\n");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

int pre(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    return 0;
}

int isOperand(char x){
    if(x=='-'||x=='+' || x=='/' ||x=='*'){
        return 0;
    }
    else{
        return 1;
    }
}

char *convert(char *infix){
    int i=0,j=0;
    char *postfix;
    int len = strlen(infix);
    postfix = new char[len+1];
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i]) > pre(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++]= pop();
            }
        }
    }
    while(top!=nullptr){
        postfix[j++] = pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char *infix = "a+b*c";
    char *postfix = convert(infix);
    cout<<postfix<<'\n';
    return 0;
}