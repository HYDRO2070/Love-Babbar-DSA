// in Question we have to find product - Sum of a given number
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    // int i=1;
    int prd=1;
    int sum = 0;
    while(n>0){
        int rem = n %10;
        prd = prd * rem;
        sum = sum + rem;
        n = n / 10;
    }
    printf("%d",(prd-sum));
    return 0;
}