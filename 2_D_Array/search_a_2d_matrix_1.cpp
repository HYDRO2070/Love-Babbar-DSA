// how to use Binary Search in A 2D array.
// In the Given question the matrix is sorted in row and row is sorted itself.


#include<bits/stdc++.h>
using namespace std;
// int Binary(int *ptr,int size,int t){
//     int left = 0;
//     int right = size-1;
//     int mid = left + (right - left) / 2;
//     while(left <= right){
//         if((*ptr + mid) == t){
//             return mid;
//         }
//         else if((*ptr + mid) > t){
//             right = mid -1;
//         }
//         else{
//             left = mid +1;
//         }
//         mid = left + (right - left) / 2;
//     }
//     return -1;
// }



int Binary(int arr[][3],int c,int r,int t){
    int left = 0;
    int right = c*r - 1;
    int mid = left + (right - left) / 2;
    while(left <= right){
        if((arr[mid/c][mid%c]) == t){
            return mid;
        }
        else if((arr[mid/c][mid%c]) > t){
            right = mid -1;
        }
        else{
            left = mid +1;
        }
        mid = left + (right - left) / 2;
    }
    return -1;
}
int main(){
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};

    // using pointer approach
    // int len = 3 * 3;
    // int *ptr = &(arr[0][0]);
    // cout<<Binary(ptr,len,10);

    // using Normal approach
    cout<<Binary(arr,3,3,6);
    // cout<<(*ptr + len);
    return 0;
}