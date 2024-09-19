// Bridge - it's meaning is that the edge which is connecting the two component. or we can say that the edge when it is remove from the graph the no. of the component will increse than that edge is know as bridges.
// to solve this first is brute force which can be solve as. visiting every edges and removing it and apply dfs if the no. of component get's increse than it's a bridge or apply same method to other edge which is not visited.

#include<bits/stdc++.h>
using namespace std;

template<typename t>
class graph{
    public:
    unordered_map<t,list<t> > adj;

    void insert_edge(int u,int v,int dir){
        adj[v];
        adj[u].push_back(v);
        if(!dir)
        adj[v].push_back(u);
    }

    void print(){
        for(auto i : adj){
            cout<<i.first<<"-> ";
            for(auto j : i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }


};

// int min(int a,int b){
//     return min(a,b);
// }

void dfs(graph<int> &g,int &time,int node,vector<bool> &visited,vector<int> &disc,vector<int> &low,int parent,vector<vector<int> > &ans){
    // cout<<"hello"<<node<<endl;
    visited[node] = true;
    disc[node] = low[node] = time++;

    for(int i : g.adj[node]){
        if(i == parent) continue;
        if(!visited[i]){
            dfs(g,time,i,visited,disc,low,node,ans);
            low[node] = min(low[node],low[i]);

            if(low[i] > disc[node]){
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(i);
                ans.push_back(temp);
            }
        }
        else{
            // Back edge
            low[node] = min(low[node],disc[i]);
        }
    }
}


vector<vector<int> > bridges(graph<int> &g){
    int n = g.adj.size();
    vector<vector<int> > ans;
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    vector<bool> visited(n,false);
    int time = 0;
    int parent = -1;

    for(int i = 0;i < n; ++i){
        if(!visited[i])
        dfs(g,time,i,visited,disc,low,parent,ans);
    }
    return ans;
}


int main(){
    graph<int> g;
    g.insert_edge(0,1,0);
    g.insert_edge(0,2,0);
    g.insert_edge(0,3,0);
    g.insert_edge(1,2,0);
    g.insert_edge(3,4,0);
    g.print();
    vector<vector<int> > ans = bridges(g);
    for(int i =0;i < ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}