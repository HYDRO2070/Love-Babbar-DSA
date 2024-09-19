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


vector<int> shortest_path(graph<int> &g,int s,int d){
    int n = g.adj.size();
    vector<int> parent(n+1,-1);
    vector<bool> visited(n+1,0); 
    queue<int> q;
    vector<int> ans;
    q.push(s);

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        visited[temp] = true;

        for(auto i : g.adj[temp]){
            if(!visited[i]){
                if(parent[i] == -1)parent[i] = temp;
                q.push(i);
            }
        }
    }
    int i = d;
    while(i != s){
        ans.push_back(i);
        // ans.push_back(parent[i]);
        i = parent[i];
    }
    ans.push_back(s);
    reverse(ans.begin(),ans.end());
    return ans;
}


int main(){
    graph<int> g;
    g.insert_edge(1,2,0);
    g.insert_edge(1,3,0);
    g.insert_edge(1,4,0);
    g.insert_edge(2,5,0);
    g.insert_edge(3,8,0);
    g.insert_edge(4,6,0);
    g.insert_edge(6,7,0);
    g.insert_edge(5,8,0);
    g.insert_edge(7,8,0);
    g.print();
    vector<int> ans = shortest_path(g,1,7);
    for(int i = 0;i < ans.size();++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}