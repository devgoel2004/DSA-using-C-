#include<bits/stdc++.h>
using namespace std;
struct Array{
    int *A;
    int size;
    int length;
};
void Display(struct Array arr){
    int i;
    printf("Element are\n");
    for(i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}
int main(){
    struct Array arr;
    printf("Enter size of an array");
    scanf("%d",&arr.size);
    arr.A = new int[arr.size];
    arr.length =0;
    int n,i;
    printf("Enter the number of elements");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr.A[i]);
    }
    arr.length = n;
    Display(arr);
    return 0;
}