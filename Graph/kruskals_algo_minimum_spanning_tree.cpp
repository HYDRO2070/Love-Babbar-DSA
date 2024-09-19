// Disjoint set - it help when we have too many component in the graph like g1,g2,g3 ... like this.
// 2 important operation - findparent or findset and Union or Unionset.
// Union by Rank and Path Compression



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

// setting the default value in the data structure
void makeset(vector<int> &parent,vector<int> &rank,int n){
    for(int i = 1;i <= n;++i){
        parent[i] = i;
        rank[i] = 0;
    }
}

// we use this function to find the parent of the node
int findparent(vector<int> &parent,int node){
    if(parent[node] == node) return node;
    // here we are using the concept of the path compression.
    return parent[node] = findparent(parent,parent[node]);
}

// if two node have different parent than we merge them using this function
void Unionset(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findparent(parent,u);
    v = findparent(parent,v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

// this is the kruskal algorithm function which return the weight of the minimum spanning tree.
int kruskals_algorith(graph<int> &g){
    int n = g.adj.size();

    // we create this vector to store the value in w u v so that we can access it fasting and efficiently
    vector<pair<int,pair<int,int> > > wlist;
    vector<bool> vt(n+1,false);
    vector<int> parent(n+1);
    vector<int> rank(n+1);
    int minweight = 0;
    makeset(parent,rank,n);

    // adding weight in the list
    for(int i = 1;i <= n;i++){
        if(!vt[i]){
            vt[i] = true;
            for(auto j : g.adj[i]){
                if(!vt[j.second]){
                    pair<int,pair<int,int> > m;
                    m.first = j.first;
                    m.second.first = i;
                    m.second.second = j.second;
                    wlist.push_back(m);
                }
            }
        }
    }
    
    // sorting the weight of all edges
    sort(wlist.begin(),wlist.end());
    
    // algo of kruskal
    for(int i = 0;i < wlist.size();++i){
        int u = findparent(parent,wlist[i].second.first);
        int v = findparent(parent,wlist[i].second.second);
        int w = wlist[i].first;

        if(u != v){
            minweight += w;
            Unionset(u,v,parent,rank);
        }
    }
    return minweight;
}


int main(){
    graph<int> g;
    g.insert_edge(1,2,2,0);
    g.insert_edge(1,4,1,0);
    g.insert_edge(1,5,4,0);
    g.insert_edge(4,5,9,0);
    g.insert_edge(4,3,5,0);
    g.insert_edge(2,4,3,0);
    g.insert_edge(2,3,3,0);
    g.insert_edge(2,6,7,0);
    g.insert_edge(3,6,8,0);
    g.print();
    cout<<kruskals_algorith(g);
    return 0;
}