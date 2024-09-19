// Reverse the Given Number Till 32-bit or Return Zero.
#include<iostream>
using namespace std;
int main(){
    int a;
    int result = 0;
    cin>>a;
    while(a){
        if(a*10 > __INT_MAX__/10){
            cout<<"Hello Wolrd";
        }
        int temp = a%10;
        result = result * 10 + temp;
        a = a/10;
    }
    cout<<result;
    return 0;
}