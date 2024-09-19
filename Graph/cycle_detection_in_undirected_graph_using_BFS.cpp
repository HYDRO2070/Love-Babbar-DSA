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


bool solve(graph<int> &g,queue<int> &q,unordered_map<int,bool> &visited,unordered_map<int,int> &parent){
    if(q.empty()) return true;
    int temp = q.front();
    q.pop();
    visited[temp] = true;
        // cout<<"-------"<<temp<<endl;
    for(auto i : g.adj[temp]){
        if(!visited[i]){
            parent[i] = temp;
            q.push(i);
        }
        else{
            // cout<<i << " "<<parent[temp]<<endl;
            if(i == parent[temp]) continue;
            else return false;
        }
    }
    return solve(g,q,visited,parent);
}


bool cycle_detection_BFS(graph<int> &g){
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    
    bool temp = true;
    for(int i = 1;i < g.adj.size();i++){
        if(!visited[i]){
            // cout<<visited[i]<<" "<<i<<endl;
            q.push(i);
            parent[i] = -1;
            temp &= solve(g,q,visited,parent);
            if(!temp) break;
        }
    }
    return temp;
}


int main(){
    graph<int> g;
    g.insert_edge(1,2,0);
    g.insert_edge(2,3,0);
    g.insert_edge(4,5,0);
    g.insert_edge(5,6,0);
    g.insert_edge(5,7,0);
    g.insert_edge(6,8,0);
    g.insert_edge(7,8,0);
    g.insert_edge(8,9,0);
    g.print();
    cout<<cycle_detection_BFS(g)<<endl;
    return 0;
}