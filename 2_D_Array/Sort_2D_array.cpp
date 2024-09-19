// let's say we are using selection sort to sort this matrix.

#include<bits/stdc++.h>
using namespace std;
void printarray(int arr[][3],int c,int r){
    for(int i =0;i<c;i++){
        for(int j =0;j<r;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int minpos(int *ptr,int s,int e){
    int min = s;
            // cout<<"-"<<s<<" "<<e<<endl;
    // int i = -1;
    for(int i = s + 1;i<=e;i++){
            // cout<<"--"<<*ptr+min<<" "<<*ptr+i<<endl;
        if(*(ptr+min) > *(ptr+i)){
            min = i;
        }
    }
    return min;
}
void swap1(int *ptr,int a,int b){
            // cout<<"-"<<a<<" "<<b<<endl;
    // cout<<*(ptr + a)<<endl;
    *(ptr + a) = (*(ptr+a))+ (*(ptr+b));
    // cout<<*(ptr + a)<<endl;
    *((ptr+b)) = (*(ptr+a))- (*(ptr+b));
    *((ptr+a))= (*(ptr+a))- (*(ptr+b));
}
void selection_sort(int *ptr,int len){
    int pivot = 0;
    for(int i = 0;i<len-1;i++){
        int min = minpos(ptr,i,len-1);
        cout<<min<<endl;
        if(i!=min){
            // swap(*ptr+i,*ptr+min);
        swap1(ptr,i,min);
        }
    }
}
int main(){
    int arr[3][3] = {2,4,6,1,87,5,343,66,-1};

    
    int *ptr = &(arr[0][0]);
    int len = 3*3;
    // int size = sizeof(arr) / sizeof(int);
    printarray(arr,3,3);
    selection_sort(ptr,len);
    printarray(arr,3,3);
    cout<<"Complete";
    return 0;
}