#include<iostream>
#include<vector>
using namespace std;
int jumpgame(vector<int> arr){
    int maxi = 0;
    int count = 0;
    for(int i= 0;i<arr.size();i++){
        if(i > maxi){
            return false;
        }
        if((i + arr[i]) > maxi){
            maxi = i + arr[i];
            count++;
        }
        if(maxi >= arr.size()){
            break;;
        }
    }
    return count;
}
int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(4);
    cout<<jumpgame(arr);
    return 0;
}