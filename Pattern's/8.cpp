#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j = 1;
        while((j+i-1)<n){
            cout<<" ";
            j = j + 1;
        }

        // while(j){
        //     cout<<" ";
        //     j = j - 1;
        // }

        // while (j){
        //     cout<<"*";
        //     j = j - 1;
        // }
        j = 1;
        while (j<=i){
            cout<<j;
            j = j + 1;
        }
        j = j -2;
        while(j){
            cout<<j;
            j = j - 1;
        }
        cout<<endl;
        i = i + 1;        
    }
    return 0;
}