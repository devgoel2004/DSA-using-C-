#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode *left;
    int val;
    TreeNode *right;
    TreeNode (int val){
        this->val = val;
        left=nullptr;
        right = nullptr;
    }
}*root=nullptr;
//function to create a binary tree using stack
void Create() {
    TreeNode *p, *t;
    int x;
    queue<TreeNode*> q;
    printf("Enter root value: ");
    scanf("%d", &x);
    root = new TreeNode(x);
    q.push(root);
    
    while (!q.empty()) {
        p = q.front();
        q.pop();
        
        printf("Enter left child of %d (-1 for no child): ", p->val);
        scanf("%d", &x);
        if (x != -1) {
            t = new TreeNode(x);
            p->left = t;
            q.push(t);
        }
        
        printf("Enter right child of %d (-1 for no child): ", p->val);
        scanf("%d", &x);
        if (x != -1) {
            t = new TreeNode(x);
            p->right = t;
            q.push(t);
        }
    }
}


void preorder(class TreeNode *p){
    if(p){
        printf("%d ",p->val);
        preorder(p->left);
        preorder(p->right);
    }
}
int main(){
    Create();
    preorder(root);
    return 0;
}