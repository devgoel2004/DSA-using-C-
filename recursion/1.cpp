#include<bits/stdc++.h>
using namespace std;
void func(int n){
    if(n>0){
        printf("%d",n);
        func(n-1);
    }
}
void func2(int n){
    if(n>0){
        func2(n-1);
        cout<<n;
    }
}
int main(){
    int x=3;
    func(x);
    cout<<'\n';
    func2(x);
    return 0;
}