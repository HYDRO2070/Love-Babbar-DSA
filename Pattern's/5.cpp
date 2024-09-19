#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j = 1;
        while (j<=n){
        // while (j<=i){
            // cout<<char('A'+ i + j - 1)<<" ";
            // cout<<char('A'+ i + j - 2)<<" ";
            cout<<char('A'+ i - 1)<<" ";
            j = j + 1;
        }
        cout<<endl;
        i = i + 1;        
    }
    return 0;
}