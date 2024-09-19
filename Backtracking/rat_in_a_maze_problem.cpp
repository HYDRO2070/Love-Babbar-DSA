#include<bits/stdc++.h>
using namespace std;


void find(int arr[][4],int n,int x,int y,string path,vector<vector<bool> > &vt,vector<string> &ans){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    vt[x][y] = 1;

    if(arr[x+1][y] == 1 && vt[x+1][y] == 0 && (x+1 >= 0 && x+1 < n) && (y >= 0 && y < n)){
        find(arr,n,x+1,y,path+'D',vt,ans);
    }
    if(arr[x][y-1] == 1 && vt[x][y-1] == 0 && (x >= 0 && x < n) && (y-1 >= 0 && y-1 < n)){
        find(arr,n,x,y-1,path+ 'L',vt,ans);
    }
    if(arr[x][y+1] == 1 && vt[x][y+1] == 0 && (x >= 0 && x < n) && (y+1 >= 0 && y+1 < n)){
        find(arr,n,x,y+1,path+ 'R',vt,ans);
    }
    if(arr[x-1][y] == 1 && vt[x-1][y] == 0 && (x-1 >= 0 && x-1 < n) && (y >= 0 && y < n)){
        find(arr,n,x-1,y,path+ 'U',vt,ans);
    }


    vt[x][y] = 0;

}


vector<string> solve(int arr[][4],int size){
    vector<string> ans;
    vector<vector<bool> > visited(size,vector<bool>(size,0));
    string path = "";
    find(arr,size,0,0,path,visited,ans);
    return ans;
}

int main(){
    int arr[4][4] = {
        {1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}
    };

    vector<string> ans = solve(arr,4);
    for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}