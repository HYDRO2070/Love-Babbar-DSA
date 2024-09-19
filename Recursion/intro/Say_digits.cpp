// in this question we have been given number and we have to print it in english using A-Z.
// input - 421
// output- four two one

#include<bits/stdc++.h>
using namespace std;

void printnum(string s[],int num){
    if(num <= 0){
        return;
    }
    printnum(s,num/10);
    cout<<s[num%10]<<" ";
}

int main(){
    string s[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int num = 421;
    printnum(s,num);
    return 0;
}