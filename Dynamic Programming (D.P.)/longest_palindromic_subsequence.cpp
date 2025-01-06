// as the name suggest we have to find longest palindrom subsequence in the given string and eturn its length.

#include<bits/stdc++.h>
using namespace std;

int find(string s1){
    string s2 = s1;
    int n = s1.size();
    reverse(s2.begin(),s2.end());
    vector<int> next(n+1,0);
    vector<int> curr(n+1,0);
    for(int i = n-1;i >= 0;i--){
        for(int j = n-1;j >= 0;j--){
            int ans = 0;
            if(s1[i] == s2[j])
                ans = 1 + next[j+1];
            else
                ans = max(next[j],curr[j+1]);
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int main(){
    string s = "bbbab";
    cout<<find(s)<<endl;
    return 0;
}