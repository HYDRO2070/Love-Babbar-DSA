#include<iostream>
#include<vector>
using namespace std;
vector<int> Reverse_k(vector<int> arr,int k){
    int s = k,e = arr.size() - 1;
    while(s <= e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    return arr;
}
void printans(vector<int> arr){
    for(int i = 0;i< arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
using namespace std;
int main(){
    vector<int> arr;
    int k = 2;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    printans(Reverse_k(arr,k-1));
    return 0;
}