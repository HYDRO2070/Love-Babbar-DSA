// in Question we have to reverse a given number
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int result = 0;
    int i = 0;
    while(n){
        int rem = n%10;
        n = n/10;
        if(rem == 1){
            result = result + pow(2,i);
        }
        i++;
    }
    
    cout<<result;
    return 0;
}