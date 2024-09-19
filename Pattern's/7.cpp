#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char c = 'A'+ n - 1;
    int i = 1;
    while(i<=n){
        int j = 1;
        while (j<=i){
            cout<<char(c - i + j)<<" ";
            j = j + 1;
        }
        cout<<endl;
        i = i + 1;        
    }
    return 0;
}