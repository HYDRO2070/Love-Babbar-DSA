// sieve of eratostheres

#include<bits/stdc++.h>
using namespace std;
int countprime(int num){
    int cnt = 0;
    vector<bool> prime(num+1,true);
    prime[0] = prime[1] = false;
    for(int i = 2;i<num;i++){
        if(prime[i]){
            cnt++;
            for(int j = 2*i;j < num;j = j+i){
                prime[j] = false;
            }
        }
    }
    return cnt;
}
int main(){
    int num;
    cin>>num;
    cout<<countprime(num);
    return 0;
}