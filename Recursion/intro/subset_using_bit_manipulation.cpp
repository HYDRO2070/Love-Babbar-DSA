// we have to find subset using bit manipulation

#include<bits/stdc++.h>
using namespace std;


vector<vector<int> > subset(vector<int> &s){
    sort(s.begin(),s.end());
    int size = s.size();
    int sub = pow (2,size);
    vector<vector<int> > ans(sub,vector<int>());
    for(int i = 0;i < size;i++){
        for(int j = 0;j < sub;j++){
            if((j >> i) & 1)
            ans[j].push_back(s[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    vector<vector<int> > ans = subset(s);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}