// Dijkstra's algorithm don't sopport negative weight that when come's the concept of the bellman ford which support the negative weighted edges in the graph.
// but there is an condition where the graph should not contain any negative cycle.
// so it's mean's that we can find negative cycle in a graph using bellman ford algo.
// only apply in the directed graph



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

vector<int> shortest_path(graph<int> &g,int s){
    int n = g.adj.size();
    vector<int> distance(n+1,INT_MAX);
    distance[s] = 0;
    distance[0] = -1;

    vector<vector<int> > wl;

    // creating array of the all edges
    for(int i = 1;i <= n; ++i ){
        vector<int> tmep;
        
        for(auto j : g.adj[i]){
            tmep.push_back(i);
            tmep.push_back(j.first);
            tmep.push_back(j.second);
        }
        if(tmep.size() > 0)
        wl.push_back(tmep);
    }

    // traverse on edge list
    for(int i = 1;i < n;++i){
        for(int j = 0;j < wl.size();++j){
            int u = wl[j][0];
            int v = wl[j][1];
            int w = wl[j][2];
            distance[v] = min(distance[v],distance[u]+w);
        }
    }

    // check for negative cycle in the graph
    int flag = 0;
    for(int j = 0;j < wl.size();++j){
        int u = wl[j][0];
        int v = wl[j][1];
        int w = wl[j][2];
        if(distance[v] == min(distance[v],distance[u]+w)) continue;
        else flag = 1;
    }

    if(flag) {
        vector<int> temp;
        temp.push_back(-1);
        return temp;
    }
    return distance;
}


int main(){
    graph<int> g;
    g.insert_edge(1,2,-2,1);
    g.insert_edge(2,3,-2,1);
    g.insert_edge(3,1,-1,1);
    g.print();
    vector<int> ans = shortest_path(g,1);
    for(int i = 0;i < ans.size();++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}