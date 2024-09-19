// In this we have been given 2d array and we have to rotate it by 90deg clockwise.
// 1 2 3    7 4 1
// 4 5 6    8 5 2
// 7 8 9    9 6 3

#include<bits/stdc++.h>
using namespace std;
void rotate90(int arr[][4],int c,int r){
    // for(int i = 0;i<c-2;i++){
    //     for(int j = 0;j<c-2;j++){
        int k = 1;
        for(int j = 0;j<(r/2);j++){
            int i = 0;
            int l = c-1-(j*2);
            while(i < l){
                cout<<k<<endl;
                int temp = arr[j+i][r-1-j];
                // cout<<temp<<endl;
                int temp1 = arr[c-1-j][r-1-i-j];
                // cout<<temp1<<endl;
                arr[j+i][r-1-j] = arr[j][j+i];
                // cout<<arr[j+i][r-1-j]<<endl;
                arr[c-1-j][r-1-i-j] = temp;
                temp = temp1;
                temp1 = arr[c-1-i-j][j];
                arr[c-1-i-j][j] = temp;
                arr[j][j+i] = temp1;
                i++;
                k++;
            }
        }
}
int main(){
    // int arr[5][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    // int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    // rotate90(arr,3,3);
    rotate90(arr,4,4);
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}