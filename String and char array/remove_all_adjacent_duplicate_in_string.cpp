#include<iostream>
using namespace std;
string removedupli(string s){
    int i = 0;
    while(i < s.length() - 1){
        if(s[i] == s[i+1]){
            s.erase(i,2);
            i = 0;
        }
        else{
        i++;
        }
    }
    return s;
}
int main(){
    string s = "axzzxy";
    cout<<removedupli(s);
    // cout<<s.find((s[1] + s[1]));
    return 0;
}