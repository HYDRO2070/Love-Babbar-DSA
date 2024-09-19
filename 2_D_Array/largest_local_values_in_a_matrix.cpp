// we have been given a matrix and we have to return max value of every 3*3 matrix and return in matrix also.
// 9 9 8 1     
// 5 6 2 6     ->   9 9
// 8 2 6 4          8 6
// 6 2 2 2


#include<bits/stdc++.h>
using namespace std;

// int maxvalue(int arr[][10],int c,int r){
//     int maxi = 0;
//     for(int i = c;i<c+3;i++){
//         for(int j = r;j<r+3;j++){
//             // cout<<arr[i][j]<<endl;
//             maxi = max(maxi,arr[i][j]);
//         }
//     }
//     // cout<<maxi <<" "<<c <<" "<<r<<endl;
//     return maxi;
// }
// vector<vector<int> > find(int arr[][10],int c,int r){
//     vector<vector<int> > ans(c-2);
//     int i = 0;
//     int j = 0;
//     // vector<int> ans;
//     while(j+2 < c){
//         // cout<<j<<i<<endl;
//         // ans.push_back();
//         ans[j].push_back(maxvalue(arr,j,i));
//         if(i+3 < c){
//             i++;
//         }
//         else{
//             j++;
//             i = 0;
//         }
//     }
    
//     return ans;
// }

// ANother Approach

vector<vector<int> > find(vector<vector<int> > grid){
    int i = 0;
    int j = 0;
    int n = grid.size();
    while(j+2 < n){
        int maxi = 0;
        for(int k = j;k < j+3;k++){
            for(int l = i;l < i+3;l++){
                maxi = max(maxi,grid[k][l]);
            }
        }
        grid[j][i] = maxi;
        if(i+3 < n){
            i++;
        }
        else{
            j++;
            i = 0;
        }
    }
    grid.resize(n-2);
    for(i = 0;i < grid.size();i++){
        grid[i].resize(n-2);
    }
    return grid;
}



int main(){
    // int arr[4][4] = {9,9,8,1,5,6,2,6,8,2,6,4,6,2,2,2};
    // int arr[5][5] = {1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1};
    // int arr[10][10] = {{20,8,20,6,16,16,7,16,8,10},
    // {12,15,13,10,20,9,6,18,17,6},
    // {12,4,10,13,20,11,15,5,17,1},
    // {7,10,14,14,16,5,1,7,3,11},
    // {16,2,9,15,9,8,6,1,7,15},
    // {16,2,9,15,9,8,6,1,7,15},
    // {16,2,9,15,9,8,6,1,7,15},
    // {16,2,9,15,9,8,6,1,7,15},
    // {16,2,9,15,9,8,6,1,7,15},
    // {16,2,9,15,9,8,6,1,7,15}};
    
    // arr[0][0] = -1;
    // cout<<arr[0][0];
    // int size = 16;
    // vector<vector<int> > ans = find(arr,10,10);
    // vector<vector<int> > ans = find(arr,10,10);
    // for(int i = 0;i < ans.size();i++){
    //     for(int j = 0;j < ans[0].size();j++){
    //     cout<<ans[i][j]<<" ";

    //     }
    //     cout<<endl;
    // }

    return 0;
}