#include<iostream>
#include<vector>
using namespace std;
bool jumpgame(vector<int> arr){
    int maxi = 0;
    for(int i= 0;i<arr.size();i++){
        if(i > maxi){
            return false;
        }
        maxi = (i + arr[i]) > maxi?i + arr[i]:maxi;
        if(maxi >= arr.size()){
            return true;
        }
    }
}
int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(4);
    cout<<jumpgame(arr);
    return 0;
}