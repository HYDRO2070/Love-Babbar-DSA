// there is a maze which represent 2d array. and a rat which is want to get out of that maze. the maze contain 0,1. 0 mean path is block and 1 mean open.
// so how many path there are in maze to rat to escape.
// and return the no of operation required by the rat for every path. return sum of all.

#include<bits/stdc++.h>
using namespace std;

void solve(int arr[][4],int n,int x,int y,string path,vector<vector<int> > vt,vector<string>& ans){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
    }
    

    if(arr[x+1][y] == 1 && vt[x+1][y] == 0 && (x+1 >= 0 && x+1 < n) && (y >= 0 && y < n)){
        vt[x][y] = 1;
        path.push_back('D');
        solve(arr,n,x+1,y,path,vt,ans);
        path.erase(path.size()-1);
        vt[x][y] = 0;
    }
    if(arr[x][y-1] == 1 && vt[x][y-1] == 0 && (x >= 0 && x < n) && (y-1 >= 0 && y-1 < n)){
    vt[x][y] = 1;
        path.push_back('L');
        solve(arr,n,x,y-1,path,vt,ans);
        path.erase(path.size()-1);
        vt[x][y] = 0;
    }
    if(arr[x][y+1] == 1 && vt[x][y+1] == 0 && (x >= 0 && x < n) && (y+1 >= 0 && y+1 < n)){
    vt[x][y] = 1;
        path.push_back('R');
        solve(arr,n,x,y+1,path,vt,ans);
        path.erase(path.size()-1);
        vt[x][y] = 0;
    }
    if(arr[x-1][y] == 1 && vt[x-1][y] == 0 && (x-1 >= 0 && x-1 < n) && (y >= 0 && y < n)){
    vt[x][y] = 1;
        path.push_back('U');
        solve(arr,n,x-1,y,path,vt,ans);
        path.erase(path.size()-1);
        vt[x][y] = 0;
    }


    
}

vector<string> find(int arr[][4],int s){
    vector<string> ans;
    if(arr[0][0] == 0){
        return ans;
    }
    int x = 0;
    int y = 0;
    vector<vector<int> > vt(s);
    for(int i = 0;i < s;i++){
        for(int j= 0;j < s;j++){
            vt[i].push_back(0);
        }
    }
    string path = "";
    solve(arr,s,x,y,path,vt,ans);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int arr[4][4] = {
        {1,1,1,1},
        {1,1,0,1},
        {1,1,0,1},
        {0,1,1,1},
        // {1,1,0,0,0},
    };
    vector<string> ans = find(arr,4);
    for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}