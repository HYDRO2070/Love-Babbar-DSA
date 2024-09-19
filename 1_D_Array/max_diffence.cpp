// As the title suggest.

#include<bits/stdc++.h>
using namespace std;

int diff(vector<int> arr){
    if(arr.size() < 2){
        return 0;
    }
    int ans = arr[1] - arr[0];
    int min = arr[0];
    for(int i = 1;i < arr.size();i++){
        if((arr[i] - min) > ans){
            ans = (arr[i] - min);
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(84);
    arr.push_back(87);
    arr.push_back(82);
    arr.push_back(84);
    arr.push_back(89);
    cout<<diff(arr);
    return 0;
}