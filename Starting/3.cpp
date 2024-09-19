// in Question we have to reverse a given number
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int rev=0;
    while(n){
        int rem = n %10;
        rev = rev*10 + rem;
        n = n / 10;
    }
    cout<<rev;
    return 0;
}