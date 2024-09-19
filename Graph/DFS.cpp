// Breadth first Search - it is an traversal technique

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
template<typename t>
class graph{
    public:
    unordered_map<t,list<t> > adj;

    void insert_edge(int u,int v,int dir){
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


// void solve(graph<int> &g,stack<int> &s,unordered_map<int,bool> &visited){
//     if(s.size() == 0) return;
//     int temp = s.top();
//     s.pop();
//     if(!visited[temp])
//     cout<<temp<<" ";
//     visited[temp] = true;
//     for(auto i : g.adj[temp]){
//         if(!visited[i])
//         s.push(i);
//     }
//     solve(g,s,visited);
//     return;
// }


void solve(graph<int> &g,int node,unordered_map<int,bool> &visited){
    cout<<node<<" ";
    visited[node] = true;
    for(auto i : g.adj[node]){
        if(!visited[i])
        solve(g,i,visited);
    }
}

void DFS(graph<int> g){
    unordered_map<int,bool> visited;
    // stack<int> s;
    // s.push(0);
    cout<<"DFS -> "<<endl;
    for(int i = 0;i < g.adj.size();i++){
        if(!visited[i])
        // solve(g,s,visited);
        solve(g,i,visited);
    }
    cout<<endl;
}



int main(){
    graph<int> g;
    g.insert_edge(0,2,0);
    g.insert_edge(2,1,0);
    g.insert_edge(2,4,0);
    g.insert_edge(3,1,0);
    g.insert_edge(4,3,0);
    g.print();
    DFS(g);
    return 0;
}