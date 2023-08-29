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
void Delete(struct Array *arr, int index){
    int i;
    int x=0;
    if(index>=0 && index<arr->length){
        x = arr->A[index];
        for(i=index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
    cout<<x<<'\n';
}
int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    Delete(&arr,3);
    Display(arr);
    return 0;
}