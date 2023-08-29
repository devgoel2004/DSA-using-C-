#include<bits/stdc++.h>
using namespace std;
struct Array{
    int A[10];
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
void Reverse(struct Array *arr){
    int *B;
    int i,j;
    B = new int[arr->length];
    for(i=arr->length-1,j=0;i>=0;i--,j++){
        B[j]=arr->A[i];
    }
    for(i=0;i<arr->length;i++){
        arr->A[i] = B[i];
    }
}
void Reverse2(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        swap(arr->A[i],arr->A[j]);
    }
}
int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    Reverse2(&arr);
    Display(arr);
    return 0;
}