#include<iostream>
#include<vector>
using namespace std;
void printans(vector<int> ans){
    for(int i =0;i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
// void printwave(int arr[][4],int c,int r){
//     for(int i = 0;i<c;i++){
        
//         // cout<<i<<endl;
//         for(int j = 0;j<r;j++){
//             // i - col  j- row
//             // 1 2 3    1 4 7
//             // 4 5 6    8 5 2
//             // 7 8 9    3 6 9

//             // reversing row
//             // if(i&1){
//             // cout<<arr[i][j]<<" ";
//             // }
//             // else{
//             // cout<<arr[i][3-1-j]<<" ";
//             // }

//             // // reversing col
//             if(j&1){
//             cout<<arr[j][i]<<" ";
//             }
//             else{
//             cout<<arr[j][c-1-i]<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }


vector<int> calwave(int arr[][3],int c,int r){
    vector<int> ans;
    for(int i = 0;i<c;i++){
        if(i&1){
            for(int j = r-1;j >=0;j--){
                cout<<arr[j][i]<<" ";
                ans.push_back(arr[j][i]);
            }
        }
        else{
            for(int j = 0;j <r;j++){
                cout<<arr[j][i]<<" ";
                ans.push_back(arr[j][i]);
            }
        }
        cout<<endl;
    }
    return ans;
}
int main(){
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    // int arr[2][3] = {1,2,3,4,5,6};
    
    // for(int i =0;i<2;i++){
    //     for(int j =0;j<3;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> ans = calwave(arr,3,3);
    printans(ans);
    return 0;
}