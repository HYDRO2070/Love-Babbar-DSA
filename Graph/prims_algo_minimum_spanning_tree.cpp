// MST - MInimum spanning tree.
// spanning tree - if you convert a graph into a tree such that it have (N) nodes and (N-1) edges and secondly every node is reachable by every other node that tree is know as spanning tree.
// the cost of the tree should be the minimum. because there can be many tree which will qualify above condition so we have to choose the minimum among them.
// to find a minimum spanning tree there are two mwthod which are 
                                        // -> prim's algorith
                                        // -> kruskal's algorith

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
template<typename t>
class graph{
    public:
    unordered_map<t,list<pair<t,t> > > adj;

    void insert_edge(int u,int v,int w,int dir){
        adj[v];
        adj[u].push_back({w,v});
        if(!dir)
        adj[v].push_back({w,u});
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

vector<int> prims_algorith(graph<int> &g,int s){
    int n = g.adj.size();
    vector<int> keys(n,INT_MAX);
    vector<bool> vt(n,false);
    vector<int> parent(n,-1);
    // set<pair<int,int> > m;
    priority_queue<pair<int,int> > m;
    keys[s] = 0;
    parent[s] = -1;
    m.push(make_pair(0,s));
    // m.insert(make_pair(0,s));
    vt[s] = true;
    while(!m.empty()){
        // pair<int,int>  temp = *m.begin();
        pair<int,int>  temp = m.top();
        // m.erase(m.begin());
        m.pop();

        for(auto i : g.adj[temp.second]){
            if(!vt[i.second]){
                parent[i.second] = temp.second;
                vt[i.second] = true;
                keys[i.second] = min(keys[i.second],keys[temp.second] + i.first);
                // m.insert(i);
                m.push(i);
            }
        }
    }
    return parent;
}


int main(){
    graph<int> g;
    g.insert_edge(0,1,2,0);
    g.insert_edge(0,3,6,0);
    g.insert_edge(1,2,3,0);
    g.insert_edge(1,3,8,0);
    g.insert_edge(1,4,5,0);
    g.insert_edge(4,2,7,0);
    g.print();
    vector<int> ans = prims_algorith(g,0);
    for(int i = 0;i < ans.size();++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}