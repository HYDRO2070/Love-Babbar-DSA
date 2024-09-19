// Articulation point can be explain as a node in the graph if it was remove from the graph and the no. of component in the graph will increase.


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



void dfs(graph<int> &g,int &time,int node,vector<bool> &visited,vector<int> &disc,vector<int> &low,int parent,vector<int> &ans){
    // cout<<"hello"<<node<<endl;
    visited[node] = true;
    disc[node] = low[node] = time++;

    for(int i : g.adj[node]){
        if(i == parent) continue;
        if(!visited[i]){
            dfs(g,time,i,visited,disc,low,node,ans);
            low[node] = min(low[node],low[i]);

            if(low[i] >= disc[node] && parent != -1){
                ans.push_back(node);
            }
        }
        else{
            // Back edge
            low[node] = min(low[node],disc[i]);
        }
    }
}


vector<int> bridges(graph<int> &g){
    int n = g.adj.size();
    vector<int> ans;
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    vector<bool> visited(n,false);
    int time = 0;
    int parent = -1;

    if(g.adj[0].size() > 1) ans.push_back(0);

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
    vector<int> ans = bridges(g);
    for(int i =0;i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}