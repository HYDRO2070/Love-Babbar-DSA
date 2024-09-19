#include<bits/stdc++.h>
using namespace std;
int stairs(int num){
    if(num < 0){
        return 0;
    }
    if(num == 0)
    return 1;
    return stairs(num-1) + stairs(num-2);
}
int main(){
    int num;
    cin>>num;
    cout<<stairs(num);
    return 0;
}