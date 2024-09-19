#include<iostream>
using namespace std;
bool check(int a[26],int a1[26]){
    for(int i = 0;i<26;i++){
        if(a[i] != a1[i]){
            return false;
        }
    }
    return true;
}
bool isperthere(string s1,string s2){
    int count1[26] = {0};
    int size = s1.length();
    for(int i = 0;i<size;i++){
        count1[s1[i] - 'a']++;
    }
    int count2[26] = {0};
    int i = 0;
    while(i<size && i < s2.length()){
        count2[s2[i] - 'a']++;
        i++;
    }
    if(check(count1,count2))
        return true;
    while(i < s2.length()){
        count2[s2[i] - 'a']++;
        count2[s2[i-size] - 'a']--;
        if(check(count1,count2))
            return true;
        i++;
    }
    return false;
}
int main(){
    string str = "ab";
    string str1 = "e";
    cout<<isperthere(str,str1);
    return 0;
}