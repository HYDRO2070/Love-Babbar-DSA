#include<iostream>
#include<vector>
using namespace std;
void printans(vector<int> arr){
    for(int i = 0;i< arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
vector<int> movezero(vector<int> arr){
    // int i =0,j = arr.size()-1;
    // while(i<j){
    //     if(arr[i] == 0){
    //         while(arr[j]==0){
    //             j--;
    //         }
    //         swap(arr[i],arr[j]);
    //         j--;
    //     }
    //     i++;
    // }
    int i = 0;
    for(int j = 0;j < arr.size();j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    return arr;
}
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(4);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(1);
    printans(movezero(arr));
    return 0;
}