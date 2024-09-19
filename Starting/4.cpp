// in Question we have to reverse a given number
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int result=~n+1;
    // while(n){
    //     int rem = n%2;
    //     n = n/2;
    //     result = result*10 +rem;
    // }
    // int i = 0;
    // while(n){
        // int rem = n%2;
        // n = n/2;
    //     result = ((n&1) * (pow(10,i))) + result;
    //     n = n >> 1;
    //     i++;
    // }
    // n=0;
    // while(result){
    //     int rem = result%10;
    //     result= result/10;
    //     n = n*10 +rem;
    // }
    // n = n /10;
    cout<<result;
    return 0;
}