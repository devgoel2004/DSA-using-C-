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


void levelOrder(TreeNode *p){
    queue <TreeNode*> q;
    printf("%d ",p->val);
    q.push(p);
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->left){
            printf("%d ",p->left->val);
            q.push(p->left);
        }
        if(p->right){
            printf("%d ",p->right->val);
            q.push(p->right);
        }
    }
}
int main(){
    Create();
    levelOrder(root);
    return 0;
}