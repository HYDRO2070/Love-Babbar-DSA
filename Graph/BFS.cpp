// Breadth first Search - it is an traversal technique

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// template<typename t>
class graph{
    public:
    unordered_map<int,list<int> > adj;

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


void solve(graph &g,queue<int> &q,unordered_map<int,bool> &visited){
    // cout<<"Hello"<<endl;
    if(q.size() == 0) return;
    // while(visited[q.front()])
    // q.pop();
    // if(q.size() == 0) return;
    int temp = q.front();
    q.pop();
    visited[temp] = true;
    cout<<temp<<" ";
    for(int i :g.adj[temp]){
        if(!visited[i])
        q.push(i);
    }
    solve(g,q,visited);
    return;
}

void BFS(graph g){
    queue<int> q;
    unordered_map<int,bool> visited;
    q.push(0);
    cout<<" BFS -> "<<endl;
    for(int i = 0;i < g.adj.size();i++){
        if(!visited[i])
        solve(g,q,visited);
    }
    cout<<endl;
}



int main(){
    graph g;
    g.insert_edge(0,3,0);
    g.insert_edge(3,1,0);
    g.insert_edge(1,2,0);
    g.insert_edge(1,4,0);
    g.print();
    BFS(g);
    return 0;
}