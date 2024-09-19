// we have to find exponent of a given number.

#include<bits/stdc++.h>
using namespace std;

// int power(int a,int b,int c){
//     int res = 1;
//     while(b > 0){
//         if(b&1){
//             res = res * a;
//         }
//         a = a*a;
//         b = b>>1;
//     }
//     return res % c;
// }

// int expo(int n,int e){
//     // cout<<e<<endl;
//     if(e == 1){
//         return n;
//     }
//     int ans = 1;
//     if(e&1){
//         ans *= n;
//     }
//     return ans * expo(n*n,e>>1);
// }
int expo(int n,int e){
    // cout<<e<<endl;
    if(e == 0){
        return 1;
    }
    if(e == 1){
        return n;
    }
    int ans = expo(n,e>>1);
    if(e&1){
        return n * ans*ans;
    }
    return ans * ans;
}

int main(){
    int num ,exp;
    cin>>num>>exp;
    cout<<expo(num,exp);
    return 0;
}