#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j<i+1;j++){
            int x = 0;
            for(int k = 0;k<j;k++){
                x=x+n-k;
            }
            if((j%2)==0){
                cout<<x+i-j+1<<" ";
            }
            else{
                cout<<x+n-i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}