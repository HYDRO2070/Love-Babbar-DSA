#include<iostream>
#include<cstring>
#include<vector>
#include<bits/basic_string.h>
using namespace std;
// string result(char arr[],int size){
//     int count[26] = {0};
//     for(int i = 0;i<size;i++){
//         count[arr[i] - 'a']++;
//     }
//     string ans = "";
//     for(int i = 0;i<26;i++){
//         char temp = 'a' + i;
//         if(count[i] > 0){

//         if(count[i] == 1){
//             ans += temp;
//         }
//         else if(count[i] < 10){
//             ans += temp;
//             ans += count[i];
//         }
//         }
//         // else{

//         // }
//     }
//     return ans;
// }

int compress(vector<char> arr){
    int i = 0;
    int index = 0;
    while(i < arr.size()){
        int j = i+1;
        while(j < arr.size() && arr[i] == arr[j]){
            j++;
        }
        arr[index++] = arr[i];
        int count = j -i;
        if(count > 1){
            string num = to_string(count);
            for(char ch: num){
                arr[index++] = ch;
            }
        }
        i = j;
    } 
    return index;
}
int main(){
    vector<char> arr;
    arr.push_back('a');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('b');
    arr.push_back('c');
    arr.push_back('c');
    arr.push_back('c');
    arr.push_back('c');
    arr.push_back('c');
    cout<<compress(arr);
    return 0;
}