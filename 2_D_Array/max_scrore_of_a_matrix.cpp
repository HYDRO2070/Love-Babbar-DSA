// in this we have given a matrix and we have to change row or column so that it has the max score.
// and by changing it mean chaning every element to opposite. like 1 to 0 or 0 to 1.
// it is binary matrix.
// explaining with example is difficult so we go to program.

#include<bits/stdc++.h>
using namespace std;

bool check(int arr[][4],int c,int r){
    int t = 0;
    for(int i = 0;i<c;i++){
        if(arr[i][r] == 0)
        t--;
        else
        t++;
    }
    return t < 0;
}

int toint(int n){

    int ans = n%10;
    n = n/10;
    int t = 2;
    while(n){
        ans = (ans) + t*(n%10);
        t *= 2;
        n /= 10;
    }
    return ans;
}

int findscore(int arr[][4],int c,int r){
    // firstly rows
    int i = 0;
    while(i < c){
        if(arr[i][0] != 1){
            for(int j = 0; j < r;j++){
                if(arr[i][j] == 0){
                    arr[i][j] = 1;
                }
                else{
                    arr[i][j] = 0;
                }
            }
        }
        i++;
    }

    // NOw column
    i = 0;
    while(i < r){
        if(check(arr,c,i)){
            for(int j = 0; j < c;j++){
                if(arr[j][i] == 0){
                    arr[j][i] = 1;
                }
                else{
                    arr[j][i] = 0;
                }
            }
        }
        i++;
    }
    int ans = 0;

    for(i = 0;i < c;i++){
        // int temp = 0;
        for(int j = 0;j < r;j++){
            // temp = (temp*10) + arr[i][j];
            // temp = (1 << temp);
            // temp = temp|arr[i][j];
            int temp = arr[i][j] << (r-j-1);
            ans +=temp;
        }
        // cout<<temp<<endl;
        // ans += toint(temp);
    }
        return ans;
    // cout<<110
    // return cal(arr,c,r);
}

int main(){
    int arr[3][4] = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    // int arr[1][20] = {{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
    // int size = 3*4;
    cout<<findscore(arr,3,4);
    // int a = 1;
    // a = 1 << a;
    // a = a|1;
    // a = 1 << a;
    // cout<<a;
    // a = a|1;
    // cout<<a;
    return 0;
}