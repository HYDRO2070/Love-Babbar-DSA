#include<iostream>
#include<vector>
using namespace std;

//Not Optimize Way TO Write This Program
// void intersection(int arr1[],int size1,int arr2[],int size2){
//     for(int i = 0;i<size1;i++){
//         for(int j= 0;j<size2;j++){
//             if(arr2[j] == arr1[i]){
//                 cout<<arr2[j]<<" ";
//                 arr2[j] = -1;
//             }
//         }
//     }
// }

//Optimized Way
void intersection(int arr1[],int size1,int arr2[],int size2){
    int i = 0;
    int j = 0;
    while(i<size1 && j<size2){
        if(arr1[i] < arr2[j]){
            i = i + 1;
        }
        else if(arr1[i] > arr2[j]){
            i = i + 1;
            j = j+ 1;
        }
        else if(arr1[i] == arr2[j]){
            cout<<arr2[j]<<" ";
            j = j + 1;
        }
    }
}
int main(){
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {2,4,6,8,0};
    int size1 = sizeof(arr1)/sizeof(int);
    int size2 = sizeof(arr2)/sizeof(int);
    intersection(arr1,size1,arr2,size2);
    return 0;
}