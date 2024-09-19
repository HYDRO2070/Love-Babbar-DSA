// 0 1 1 2 3 5 8 13 21 ....

#include<bits/stdc++.h>
using namespace std;
int fabo(int num){
    if(num == 0){
        return 0;
    }
    if(num == 1){
        return 1;
    }
    return fabo(num-1) + fabo(num-2);
}
int main(){
    int num;
    cin>>num;
    cout<<fabo(num);
    return 0;
}