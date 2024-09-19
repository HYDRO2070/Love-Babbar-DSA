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

vector<int> shortest_path(graph<int> &g,int s){
    int n = g.adj.size();
    set<pair<int,int> > m;
    vector<int> distance(n,INT_MAX);
    distance[s] = 0;
    m.insert(make_pair(0,s));
    while(!m.empty()){
        // cout<<"Hello"<<endl;
        auto temp = *m.begin();

        for(auto i : g.adj[temp.second]){
            // distance[i.second] = min(distance[i.second],distance[temp.second] + i.first);
            if(distance[i.second] > distance[temp.second] + i.first){
                distance[i.second] = distance[temp.second] + i.first;
                m.insert(make_pair(distance[i.second],i.second));
            }
        }
        // cout<<temp.second<<" "<<m.size()<<endl;
        m.erase(m.begin());
        // cout<<m.size()<<endl;
    }
    return distance;
}


int main(){
    graph<int> g;
    g.insert_edge(0,1,5,0);
    g.insert_edge(0,2,8,0);
    g.insert_edge(1,2,9,0);
    g.insert_edge(1,3,2,0);
    g.insert_edge(2,3,6,0);
    g.print();
    vector<int> ans = shortest_path(g,0);
    for(int i = 0;i < ans.size();++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}