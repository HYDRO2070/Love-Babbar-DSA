#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char c = 'A';
    int i = 1;
    while(i<=n){
        int j = 1;
        // while (j<=n){
        while (j<=i){
            // cout<<char('A'+ j - 1)<<" ";
            cout<<c<<" ";
            c = char(c+1);
            j = j + 1;
        }
        cout<<endl;
        i = i + 1;        
    }
    return 0;
}