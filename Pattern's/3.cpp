#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        // int kuch = i;
        int j = 1;
        cout<<i<<" ";
        while(j<i){
            i = i + j;
            cout<<i<<" ";
            i = i - j;
            j = j + 1;
        } 
        cout<<endl;
        i = i + 1;
    }
    return 0;
}