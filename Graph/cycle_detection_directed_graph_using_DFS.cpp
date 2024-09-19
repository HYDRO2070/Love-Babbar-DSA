
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


bool solve(graph<int> &g,int node,unordered_map<int,pair<bool,bool> > &visited){
    cout<<node<<" "<<visited[node].first<<" "<<visited[node].second<<endl;
    if(visited[node].first  && visited[node].second) return false;
    visited[node].first = true;
    bool temp = true;
    visited[node].second = true;
    for(auto i : g.adj[node]){
            temp &= solve(g,i,visited);
            if(!temp) return false;
    }
    visited[node].second = false;
    return true;
}


bool cycle_directed(graph<int> &g){
    unordered_map<int,pair<bool,bool> > visited;

    bool temp = true;
    for(int i = 1;i <= g.adj.size();i++){
        if(!visited[i].first){
            visited[i].second = true; 
            temp &= solve(g,i,visited);
            visited[i].second = false; 
            if(!temp) return false;
        }
    }
    return true;
}



int main(){
    graph<int> g;
    g.insert_edge(1,2,1);
    g.insert_edge(2,3,1);
    g.insert_edge(2,4,1);
    g.insert_edge(4,5,1);
    g.insert_edge(5,6,1);
    g.insert_edge(6,4,1);
    g.insert_edge(3,7,1);
    g.insert_edge(3,8,1);
    g.insert_edge(8,7,1);
    g.print();
    cout<<g.adj.size()<<endl;
    cout<<cycle_directed(g)<<endl;
    return 0;
}