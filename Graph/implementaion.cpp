#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
template<typename t>
class graph{
    public:
    unordered_map<t,list<t> > adj;
    void addedge(t u,t v,bool direction){
        adj[u].push_back(v);
        if(!direction)
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

int main(){
    int m;
    cout<<"Enter the no of edge :"<<endl;
    cin>>m;
    graph<int> *g = new graph<int>();
    for(int i = 0;i < m;i++){
        int v,u;
        cin>>u>>v;
        g->addedge(u,v,0);
    }
    g->print();
    return 0;
}