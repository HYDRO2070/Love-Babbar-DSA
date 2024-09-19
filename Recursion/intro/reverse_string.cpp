// As the name suggest

#include<bits/stdc++.h>
using namespace std;

// string reverse(string s,int size){
//     if(size < 0){
//         return "";
//     }
//     return s[size] + reverse(s,size-1);
// }

// void reverse(string& s,int l,int r){
//     if(l > r){
//         return;
//     }
//     swap(s[l],s[r]);
//     reverse(s,l+1,r-1);
// }
void reverse(string& s,int l){
    if(l > s.size()-1-l){
        return;
    }
    swap(s[l],s[s.size()-1-l]);
    reverse(s,l+1);
}



int main(){
    string s = "abcde";
    reverse(s,0);
    cout<<s;
    return 0;
}