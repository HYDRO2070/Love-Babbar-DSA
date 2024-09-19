// topological sort - it is an linear ordering of verties such that for every edges (u -> v) u always appears before v in that ordering
// using BFS (which is also know as Kahn's Algorithm)

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



vector<int> topological_sort(graph<int> &g){
    int n = g.adj.size();
    vector<int> indg(n + 1);

    for(auto i : g.adj){
        for(auto j : i.second){
            indg[j]++;
        }
    }

    queue<int> q;
    for(int i = 1;i <=n;++i){
        if(indg[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        ans.push_back(temp);

        for(auto i : g.adj[temp]){
            indg[i]--;
            if(indg[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}


int main(){
    graph<int> g;
    g.insert_edge(1,2,1);
    g.insert_edge(1,3,1);
    g.insert_edge(2,4,1);
    g.insert_edge(3,4,1);
    g.insert_edge(4,5,1);
    g.insert_edge(4,6,1);
    g.insert_edge(5,6,1);
    g.print();
    vector<int> ans = topological_sort(g);
    for(int i = 0;i < ans.size();++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}