#include<bits/stdc++.h>
using namespace std;
bool checkprime(int num){
    if(num == 1){
        return false;
    }
    for(int i = 2;i < num;i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int num;
    cin>>num;
    cout<<checkprime(num);
    return 0;
}