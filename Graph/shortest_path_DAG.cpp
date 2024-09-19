#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
template<typename t>
class graph{
    public:
    unordered_map<t,list<pair<t,t> > > adj;

    void insert_edge(int u,int v,int w,int dir){
        adj[v];
        adj[u].push_back({v,w});
        if(!dir)
        adj[v].push_back({u,w});
    }

    void print(){
        for(auto i : adj){
            cout<<i.first<<"-> ";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }
            cout<<endl;
        }
        cout<<endl;
    }


};

void dfs(graph<int> &g,int node,vector<bool> &visited,vector<int> &topo){
    visited[node] = true;

    for(auto i : g.adj[node]){
        if(!visited[i.first])
        dfs(g,i.first,visited,topo);
    }
    topo.push_back(node);
}


vector<int> shortest_path(graph<int> &g,int s,int d){
    int n = g.adj.size();
    vector<bool> visited(n,0);
    vector<int> distance(n,INT_MAX);
    distance[s] = 0;
    vector<int> topo;

    for(int i = 0;i < n;++i){
        if(!visited[i])
        dfs(g,i,visited,topo);
    }
    reverse(topo.begin(),topo.end());
    for(int i = 0;i < n;++i){
        int temp = topo[i];
        if(distance[temp] == INT_MAX) continue;
        for(auto j : g.adj[temp]){
            distance[j.first] = min(distance[j.first],distance[temp]+j.second);
        }
    }
    return distance;
}


int main(){
    graph<int> g;
    g.insert_edge(0,1,5,1);
    g.insert_edge(0,2,3,1);
    g.insert_edge(1,2,2,1);
    g.insert_edge(1,3,6,1);
    g.insert_edge(2,3,7,1);
    g.insert_edge(2,4,4,1);
    g.insert_edge(2,5,2,1);
    g.insert_edge(3,4,-1,1);
    g.insert_edge(4,5,-2,1);
    g.print();
    vector<int> ans = shortest_path(g,1,7);
    for(int i = 0;i < ans.size();++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}