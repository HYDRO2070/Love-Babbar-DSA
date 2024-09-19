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


// first method
// bool solve(graph<int> &g,int node,unordered_map<int,bool> &visited,unordered_map<int,int> &parent){
//     visited[node] = true;
//     // cout<<"-------"<<node<<endl;
//     for(auto i : g.adj[node]){
//         if(!visited[i]){
//             parent[i] = node;
//             return solve(g,i,visited,parent);
//         }
//         else{
//             // cout<<i << " "<<parent[node]<<endl;
//             if(i == parent[node]) continue;
//             else return false;
//         }
//     }
//     return true;
// }

// second method
bool solve(graph<int> &g,int node,int parent,unordered_map<int,bool> &visited){
    
    visited[node] = true;
    // cout<<"-------"<<node<<endl;
    for(auto i : g.adj[node]){
        if(!visited[i]){
            // parent[i] = node;
            return solve(g,i,node,visited);
        }
        else{
            // cout<<i << " "<<parent[node]<<endl;
            if(i == parent) continue;
            else return false;
        }
    }
    return true;
}

bool cycle_detection_DFS(graph<int> g){
    unordered_map<int,bool> visited;
    // unordered_map<int,int> parent;

    bool temp = true;
    for(int i = 1;i < g.adj.size();i++){
        if(!visited[i]){
            // cout<<visited[i]<<" "<<i<<endl;

            // first method
            // temp &= solve(g,i,visited,parent);     

            // second method
            temp &= solve(g,i,-1,visited);

            // third method using stack. u have to do it by your self
            if(!temp) return false;
        }
    }
    return true;
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
    cout<<cycle_detection_DFS(g)<<endl;
    return 0;
}