// In This Question We Are going To convert the Given number's Binary number inverst and Return.
#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter The Number :";
    cin>>num;
    int a = num;
    int mask = 0;
    while(a){
        a = a >>1;
        mask = (mask << 1) |1;
    }
    int result = (~num)&mask;
    cout<< result;
    return 0;
}