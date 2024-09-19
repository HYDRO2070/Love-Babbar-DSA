#include<iostream>
#include<vector>
using namespace std;
void printans(vector<int> arr){
    for(int i = 0;i< arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
vector<int> Reverse_k(vector<int> arr){
    int s = 0,e = arr.size() - 1;
    while(s <= e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    return arr;
}
vector<int> addarray(vector<int> arr1,vector<int> arr2){
    int carry = 0;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    int sum = 0;
    vector<int> ans;
    while(i >= 0 && j >= 0){
        sum = arr1[i--] + arr2[j--] + carry;
        // cout<<i<<" "<<j<<endl;
        carry = sum /10;
        sum = sum % 10;
        ans.push_back(sum);

    }
    while(i >= 0 ){
        sum = arr1[i--] + carry;
        carry = sum /10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    while(j >= 0 ){
        sum = arr2[j--] + carry;
        carry = sum /10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    return Reverse_k(ans);
}
int main(){
    vector<int> arr1(1);
    vector<int> arr2;
    arr1.push_back(9);
    arr1.push_back(9);
    arr1.push_back(9);
    arr2.push_back(9);
    // arr2.push_back(9);
    // arr2.push_back(9);
    printans(addarray(arr1,arr2));
    return 0;
}