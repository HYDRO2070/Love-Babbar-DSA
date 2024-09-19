// In this We are going to find Greatest Common factor.
// Euclid's algorithm :-
//              GCD(a,b) = GCD(a-b,b) or GCD(a%b,b)
//  LCM(a,b) * GCD(a,b) = a*b

#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a == 0)
    return b;
    if(b == 0)
    return a;
    while(a!=b){
        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}