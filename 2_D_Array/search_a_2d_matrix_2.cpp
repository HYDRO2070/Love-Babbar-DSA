// In this the given matrix is sorted in rows wise and column wise also.

#include<bits/stdc++.h>
using namespace std;
bool binary2d(int arr[][5],int c,int r,int t){
    int col = 0;
    int row = r-1;
    while(col < c && row >= 0){
        if(arr[col][row] == t){
            cout<<col<<" "<<row<<endl;
            return 1;
        }
        else if(arr[col][row] > t){
            row--;
        }
        else{
            col++;
        }
    }
    return 0;
}
int main(){
    int arr[5][5] = {{1,4,7,11,15},
    {2,5,8,12,19},
    {3,6,9,16,22},
    {10,13,14,17,24},
    {18,21,23,26,30}
    };
    cout<<binary2d(arr,5,5,20);
    return 0;
}