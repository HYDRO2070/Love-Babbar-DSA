// each row have omly one queen
// each col have omly one queen
// no queen attack wach other

// complexity - 
        // time- O(n!)
        // space - n*m


#include<bits/stdc++.h>
using namespace std;

void addsolution(vector<vector<int> > &board,vector<vector<int> > &ans,int n){
    vector<int> temp;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
        // cout<<"--------------------"<<endl;
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}


// bool issafe(int row,int col,vector<vector<int> > &board,int n,map<int,bool> &d,map<int,bool> &u,map<int,bool> &m){
//     // cout<<"Hello-"<<endl;
//     for(int i = col;i >= 0;i--){
//         if(board[row][i] == 1) return false;
//     }
//     int x = row;
//     int y = col;
//     while(x >= 0 && y >= 0){
//         if(board[x][y] == 1) return false;
//         x--;
//         y--;
//     }
//     x = row;
//     y = col;
//     while(x < n && y >= 0){
//         if(board[x][y] == 1) return false;
//         x++;
//         y--;
//     }
//     return true;
// }



void find(int col,vector<vector<int> > &board,vector<vector<int> > &ans,int n,map<int,bool> &mid,map<int,bool> &down,map<int,bool> &up){
    if(col == n){
        addsolution(board,ans,n);
        return;   
    }
    
    
    for(int i =0;i < n;i++){
        if(!mid[i] && !up[(n-1) + (col - i)] && !down[i + col]){
    // cout<<"Hello--"<<endl;
        // if(issafe(i,col,board,n,down,up,mid)){
            down[i + col] = true;
            up[(n-1) + (col - i)] = true;
            mid[i] = true;
            board[i][col] = 1;
            find(col+1,board,ans,n,mid,down,up);
            board[i][col] = 0;
            down[i + col] = false;
            up[(n-1) + (col - i)] = false;
            mid[i] = false;
        }
    }
}

vector<vector<int> > solve(int n){
    vector<vector<int> > board(n,vector<int>(n,0));
    vector<vector<int> > ans;
    map<int,bool> mid;
    map<int,bool> down;
    map<int,bool> up;
    find(0,board,ans,n,mid,down,up);
    // cout<<"Hello"<<ans.size()<<endl;
    return ans;
}


int main(){
    vector<vector<int> > ans = solve(4);
    // cout<<ans.size();
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}