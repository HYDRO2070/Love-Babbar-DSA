
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


bool cyclic_detection(graph<int> &g){
    int n = g.adj.size();
    vector<int> indeg(n+1);
    for(auto i : g.adj){
        for(auto j : i.second){
            indeg[j]++;
        }
    }
    int cnt = 0;
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cnt++;

        for(auto i : g.adj[temp]){
            indeg[i]--;
            if(indeg[i] == 0) q.push(i);
        }
    }
    return (cnt == n);
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
    cout<<cyclic_detection(g)<<endl;
   
    return 0;
}