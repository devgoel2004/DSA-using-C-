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
void Append(struct Array *arr, int x){
    if(arr->length <arr->size){
        arr->A[arr->length++] =x;
    }
}
void Insert(struct Array *arr, int index, int x){
    int i;
    if(index>=0 && index<= arr->length){
        for(i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}
int BinarySearch(struct Array arr, int key){
    int l , mid,h ;
    l=0;
    h=arr.length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            h=mid-1;
        }
        else{
            h=mid+1;
        }
    }
    return -1;
}
int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    printf("%d\n",BinarySearch(arr,4));
    Display(arr);
    return 0;
}