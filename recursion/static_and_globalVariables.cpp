#include<bits/stdc++.h>
using namespace std;

int func(int n){
    static int x = 0;
    if(n>0){
        x++;
        return func(n-1)+n;
    }
    return 0;
}
int main(){
    int r;
    r=func(5);
    cout<<r;
    return 0;
}