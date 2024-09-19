// A char is said to be a special char if it appear in both lower and upper in the given string;

#include<bits/stdc++.h>
using namespace std;
int countsp(string s){
    if(s.length() < 2){
        return 0;
    }
    int arr1[26] = {0};
    int arr2[26] = {0};
    int count = 0;
    for(int i = 0;i < s.length();i++){
        if('a' <= s[i]){
            arr1[s[i] - 'a']++;
        }
        else{
            arr2[s[i] - 'A']++;
        }
    }
    for(int i = 0;i<26;i++){
        if(arr1[i] > 0 && arr2[i] > 0){
            count++;
        }
    }
    return count;

}
int main(){
    string s = "BBbab";
    cout<<countsp(s);

    // cout<<('A' < 'a');
    return 0;
}