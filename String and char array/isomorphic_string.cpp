// first string each unique char is replcae with second string each unique char than it is isomophic string and return true otherwise return False.

#include<iostream>
using namespace std;
int cal(string s){
    int arr[26] = {0};
    int count = 0;
    for(int i = 0;i < s.length();i++){
        if(arr[s[i] - 'a'] == 0){
            count++;
        }
        arr[s[i] - 'a']++;
    }
    return count;
}
bool isostring(string s1,string s2){
    return (cal(s1) == cal(s2));
}
int main(){
    string s1 ="paper";
    string s2 ="title";
    cout<<isostring(s1,s2);
    return 0;
}