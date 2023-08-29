#include<bits/stdc++.h>
using namespace std;
struct Matrix{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x){
    if(i>=j){
        m->A[i*(i-1)/2+j-1]=x;
    }
}
int Get(struct Matrix m, int i, int j){
    if(i>=j){
        return m.A[i*(i-1)/2+j-1];
    }
    return 0;
}

void Display(struct Matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
           if(i>=j){
            cout<<m.A[i*(i-1)]<<" ";
           }
           else{
            cout<<0<<" ";
           }
        }
        cout<<'\n';
    }
}
int main(){
    struct Matrix m;
    printf("Enter dimension");
    scanf("%d",&m.n);
    m.A = new int[m.n*(m.n+1)/2];
    
    return 0;
}