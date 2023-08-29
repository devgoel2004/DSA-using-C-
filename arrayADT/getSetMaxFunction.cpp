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
int Get(struct Array arr, int index){
    if(index>=0 && index< arr.length){
        return arr.A[index];
    }
    return -1;
}
void Set(struct Array *arr, int index, int x){
    if(index>=0 && index<arr->length){
        arr->A[index]= x;
    }
}
int Max(struct Array arr){
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}
int Sum(struct Array arr){
    int sum=0;
    for(int i=0;i<arr.length;i++){
        sum+=arr.A[i];
    }
    return sum;
}
float Avg(struct Array arr){
    return (float) Sum(arr)/arr.length;
}
int main(){
    struct Array arr={{2,3,4,5,6},10,5};
    Set(&arr,0,15);
    printf("Maximum is: %d\n",Max(arr));
    printf("Sum is: %d\n",Sum(arr));
    Display(arr);
    return 0;
}