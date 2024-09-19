// In this we are going to find power of any number.
// time of Normal - o(n)
// time of using this - o(log(n))

#include<bits/stdc++.h>
using namespace std;
int power(int a,int b,int c){
    int res = 1;
    while(b > 0){
        if(b&1){
            res = res * a;
        }
        a = a*a;
        b = b>>1;
    }
    return res % c;
}

// int power(int a,int b,int c){
//     int res = 1;
//     while(b > 0){
//         if(b&1){
//             res = (1ll *res * (a)%c)%c;
//         }
//         a = (1ll *(a)%c*(a)%c)%c;
//         b = b>>1;
//     }
//     return res;
// }
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<power(a,b,c);
    return 0;
}