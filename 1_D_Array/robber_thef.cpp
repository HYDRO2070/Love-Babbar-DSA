#include<iostream>
#include<vector>
using namespace std;
int getmax(vector<int> arr){
    int maxi = 0;
    for(int i =1;i<arr.size();i++){
        if(arr[maxi] < arr[i]){
            maxi = i;
        }
    }
    return maxi;
}
int getrobber(vector<int> arr){
    int count = (arr.size()- 1) / 2;
    int ans = 0;
    while(count >= 0){
        int maxi = getmax(arr);
        ans += arr[maxi];
        arr[maxi] = 0;
        if(maxi - 1 >= 0){
            arr[maxi - 1] = 0;
        }
        if(maxi + 1 < arr.size()){
            arr[maxi + 1] = 0;
        }
        count--;

    }
    return ans;
}
int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(3);
    arr.push_back(1);
    cout<<getrobber(arr);
    return 0;
}