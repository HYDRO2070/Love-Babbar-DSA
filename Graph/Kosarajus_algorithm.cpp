// this algorithm is used to find strongly connect component (SCC) in directed graph.

#include<bits/stdc++.h>
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
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }


};



void print(unordered_map<int,list<int> > adj){
    for(auto i : adj){
        cout<<i.first<<"-> ";
        for(auto j : i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void dfs(graph<int> &g,int node,vector<bool> &vt,vector<int> &ans){
    vt[node] = true;

    for(auto i : g.adj[node]){
        if(!vt[i])
        dfs(g,i,vt,ans);
    }
    ans.push_back(node);
}

void dfsnew(int node,unordered_map<int,list<int> > newadj,vector<bool> &vt,vector<int> &ans){
    vt[node] = true;
    ans.push_back(node);
    for(auto i : newadj[node]){
        if(!vt[i])
        dfsnew(i,newadj,vt,ans);
    }
}


vector<vector<int> > find_SCC(graph<int> &g){
    int n = g.adj.size();
    vector<int> topo(n);
    vector<bool> vt(n,false);
    vector<vector<int> > ans;

    // first step - create the topological sort of the graph
    for(int i = 0;i < n; ++i){
        if(!vt[i])
        dfs(g,i,vt,topo);
    }
    reverse(topo.begin(),topo.end());

    // second convert it reverse
    unordered_map<int,list<int> > newadj;
    for(int i = 0;i < n;++i){
        vt[i] = false;
        for(auto j : g.adj[i]){
            newadj[j].push_back(i);
        }
    }
    // print(newadj);
    // third apply dfs for all component and add in array and retrun
    for(int i = 0;i < n; ++i){
        int temp = topo[i];
        vector<int> t;
        if(!vt[temp])
        dfsnew(temp,newadj,vt,t);
        if(t.size() > 0)
        ans.push_back(t);
    }
    
    return ans;
}



int main(){
    graph<int> g;
    g.insert_edge(0,1,1);
    g.insert_edge(1,2,1);
    g.insert_edge(2,0,1);
    g.insert_edge(1,3,1);
    g.insert_edge(3,4,1);
    g.print();
    vector<vector<int> > ans = find_SCC(g);
    for(int i =0;i < ans.size();i++){
        for(int j =0;j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}