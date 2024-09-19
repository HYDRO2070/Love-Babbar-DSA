//leetcode question power of two
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int num;
    cout<<"ENter The GIven Number :";
    cin>>num;
    int i = 1;
    int ans = 1;
    while (i<=30)
    {   ans = ans * 2;
        if(ans == num){
            cout<<"True";
            break;
        }
        i++;
    }
    if(i>=30){
    cout<<"False";

    }
    
    return 0;
}