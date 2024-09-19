// A char is special if the index of lower last occurence is less than the index of upper of the first  occurence of the same char;
//   for exp - aA
//  it will return 1. Because it satisfy the condition.
#include<bits/stdc++.h>
using namespace std;
int countsp2(string s){
    if(s.length() < 2){
        return 0;
    }
    int arr1[26];
    int arr2[26];
    memset(arr1,-1,sizeof arr1);
    memset(arr2,-1,sizeof arr2);
    int count = 0;
    for(int i = 0;i < s.length();i++){
        if('a' <= s[i]){
            arr1[s[i] - 'a'] = i;
        }
        else{
            arr2[s[i] - 'A'] = (arr2[s[i] - 'A'] == -1) ? i : arr2[s[i] - 'A'];
            // cout<<arr2[s[i] - 'A']<<endl;
        }
    }
    for(int i = 0;i<26;i++){
        // cout<<arr1[i] <<" "<< arr2[i]<<endl;
        if(arr1[i] != -1 && arr2[i] != -1 && arr1[i] < arr2[i]){
            count++;
        }
    }
    return count;

}
int main(){
    string s = "cCceDC";
    cout<<countsp2(s);
    return 0;
}   