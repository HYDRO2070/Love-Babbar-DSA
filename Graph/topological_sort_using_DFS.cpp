// DAG - Directed Acyclic Graph
// topological sort - it is an linear ordering of verties such that for every edges (u -> v) u always appears before v in that ordering

#include<bits/stdc++.h>
#include<unordered_map>
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
                cout<<j << " ";
            }
            cout<<endl;
        }
        cout<<endl;
    }


};

void dfs(int node,graph<int> &g,vector<bool> &visited,stack<int> &s){
    visited[node] = true;
    // cout<<node<<" ";
    for(auto i : g.adj[node]){
        if(!visited[i])
        dfs(i,g,visited,s);
    }
    s.push(node);
    return;
}

vector<int> topological_sort(graph<int> &g){
    vector<bool> visited(g.adj.size()+1);
    vector<int> ans(g.adj.size());
    stack<int> s;
    
    for(int i = 1;i <= g.adj.size();i++){
        if(!visited[i])
        dfs(i,g,visited,s);
    }
    for(int i = 0;i < g.adj.size();i++){
        ans[i] = s.top();
        s.pop();
    }
    return ans;
}


int main(){
    graph<int> g;
    g.insert_edge(1,2,1);
    g.insert_edge(1,3,1);
    g.insert_edge(2,4,1);
    g.insert_edge(3,4,1);
    g.insert_edge(4,5,1);
    g.insert_edge(4,6,1);
    g.insert_edge(5,6,1);
    g.print();
    vector<int> ans = topological_sort(g);
    for(int i = 0;i < ans.size();++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}