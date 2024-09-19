//   1 2 3 4
//   5 6 7 8
//   9 10 11 12
//   13 14 15 16



#include<iostream>
#include<vector>
using namespace std;
void printans(vector<int> ans){
    for(int i =0;i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
vector<int> printspiral(int arr[][5],int c,int r){
    vector<int> ans;
    if(c < 1){
        cout<<"NULL";
        return ans;
    }
    // int index = 1;
    int index = 0;
    int size = (c%2 == 0) ? size = c/2 : size = c/2 +1;
    // if(c%2 == 0){
    //     size = c/2;
    // }
    // else{
    //     size = c/2 +1;
    // }
    for(int i = 0;i < size;i++){
        for(int j = 0 +index;j<r -index;j++){
            // cout<<arr[i][j]<<" ";
            ans.push_back(arr[i][j]);
        }
        // cout<<"-";
        for(int j = 1+index ;j<c-index;j++){
            // cout<<arr[j][r-1-index]<<" ";
            ans.push_back(arr[j][r-1-index]);
        }
        // cout<<"-";

        for(int j = r-2-index ;j>=0+index;j--){
            // cout<<arr[c-1-index][j]<<" ";
            ans.push_back(arr[c-1-index][j]);
        }
        // cout<<"-";

        for(int j = c-2-index ;j>0+index;j--){
            // cout<<arr[j][i]<<" ";
            ans.push_back(arr[j][i]);
        }
        // cout<<"-";
        index++;
        // cout<<endl;
    }
    return ans;
}
int main(){
    int arr[5][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    // int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    // int arr[3][2] = {1,2,3,4,5,6};
    // int arr[0][0];

    for(int i =0;i<5;i++){
        for(int j =0;j<5;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<int> ans = printspiral(arr,5,5);
    printans(ans);

    return 0;
}