#include<iostream>
using namespace std;
char getmaxocc(string arr){
    int arr1[26] = {0};
    for(int i = 0;i<arr.length();i++){
        arr1[arr[i] - 'a']++;
    }
    int index = 0;
    for(int i = 1;i<26;i++){
        if(arr1[index] < arr1[i]){
            index = i;
        }
    }
    return 'a' + index;
}
int main(){
    string arr;
    cin>>arr;
    cout<<getmaxocc(arr);
    return 0;
}