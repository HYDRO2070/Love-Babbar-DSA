#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    int row;
    int col;
    node(int val,int r,int c){
        this->val = val;
        this->row = r;
        this->col = c;
    }
};

class compare{
    public:
    bool operator()(node *a,node *b){
        return a->val > b->val;
    }
};


pair<int,int> solve(int arr[][3],int n,int m){
    priority_queue<node*,vector<node*>,compare> pq;
    int mini = INT_MAX,maxi = INT_MIN;
    for(int i =0;i < n;i++){
        node *temp = new node(arr[i][0],i,0);
        maxi = max(maxi,temp->val);
        mini = min(mini,temp->val);
        pq.push(temp);
    }

    int st = mini;
    int end = maxi;
    cout<<mini<<" "<<maxi<<endl;
    while(!pq.empty()){
        cout<<"hello"<<endl;
        node *temp = pq.top();
        pq.pop();
        mini = min(mini,temp->val);

        if((maxi - mini) < (end - st)){
            st = mini;
        }
        if(temp->row+1 < m){
            node *tem = new node(arr[temp->col][temp->row+1],temp->col,temp->row+1);
            pq.push(tem);
        }
    }
    return {st,end};
}

int main(){
    int arr[3][3] = {
        {2,10,11},
        {1,4,20},
        {5,6,12}
    };
    pair<int,int> ans = solve(arr,3,3);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}