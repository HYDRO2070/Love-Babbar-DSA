// in Question we have given number and we have to find the number of 1's in that number in the binary form.
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count = 0;
    while(n){
        if(n&1){
            count++;
        }
        n= n >> 1;
    }
    printf("%d",count);
    
    return 0;
}