#include<bits/stdc++.h>
using namespace std;

int celebrityis(int arr[][2],int size){
    stack<int> s;
    int ans = -1;
    for(int i = 0;i < size;i++){
        s.push(i);
    }
    while(!s.empty()){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(arr[a][b] == 1 && arr[b][a] == 0) ans = b;
        else if(arr[b][a] == 1 && arr[a][b] == 0) ans = a;
        if(ans != -1) s.push(ans);
        if(s.size() == 1){
            ans = s.top();
            s.pop();
            break;
        }
    }
    if(ans != -1){
        for(int i = 0;i < size;i++){
            if(arr[ans][i] == 1) return -1;
        }
    }
    return ans;
}


int main(){
    int arr[2][2] = {
        {0,0},
        {1,0}
    };
    cout<<celebrityis(arr,2);
    return 0;
}