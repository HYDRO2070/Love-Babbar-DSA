#include<bits/stdc++.h>
using namespace std;


int solve(string s){
    vector<int> m(32,-2);
    m[0] = -1;
    int maxlen = 0;
    int mask = 0;
    for(int i = 0;i < s.size();++i){
        switch(s[i]){
            case 'a':
                    mask^= 1;
                    break;
            case 'e':
                    mask^= 2;
                    break;
            case 'i':
                    mask^= 4;
                    break;
            case 'o':
                    mask^= 8;
                    break;
            case 'u':
                    mask^= 16;
                    break;
        }

        int prev = m[mask];
        if(prev == -2){
            m[mask] = i;
        }
        else{
            maxlen = max(maxlen,i - prev);
        }
    }
    return maxlen;
}

int main(){
    string s ="eleetminicoworoep";
    cout<<solve(s);
    return 0;
}