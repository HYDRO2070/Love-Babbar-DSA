#include<iostream>
#include<vector>
using namespace std;
void printans(vector<int> arr){
    for(int i = 0;i< arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> rotate(vector<int> arr,int k){
    // while(k){
    //     int last = arr[arr.size()-1];
    //     int j = arr.size()-1;
    //     while(j > 0){
    //         arr[j] = arr[j-1];
    //         j--;
    //     }
    //     arr[0] = last;
    //     k--;
    // }
    vector<int> ans(arr.size());
    for(int i = 0;i<arr.size();i++){
        ans[(i + k)% arr.size()] = arr[i];
    }


    return ans;
}
int main(){
    vector<int> arr;
    int k =2;
    arr.push_back(-1);
    arr.push_back(-100);
    arr.push_back(3);
    arr.push_back(99);
    printans(rotate(arr,k));
    return 0;
}