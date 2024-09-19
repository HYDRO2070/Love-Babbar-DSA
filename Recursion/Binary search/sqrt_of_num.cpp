// square root of a num using recursion binary search.

#include<bits/stdc++.h>
using namespace std;

int squareroot(int num,int l,int r){
    if(l > r){
        return l-1;
    }
    long long int mid = l + (r - l) / 2;
    if(mid * mid > num){
        return squareroot(num,l,mid-1);
    }
    else{
        return squareroot(num,mid+1,r);
    }
}

double fullsol(int num,int till,int sol){
    if(sol * sol == num){
        return sol;
    }
    double kuch = 1;
    double ans = sol;
    for(int i = 0;i < till;i++){
        kuch = kuch /10;
        ans = ans + kuch;
        while(ans * ans < num){
            ans = ans + kuch;
        }
        ans = ans - kuch;
    }
    return ans;
}

int main(){
    int num = 99;
    cout<<fullsol(num,5,squareroot(num,1,num/2));
    return 0;
}