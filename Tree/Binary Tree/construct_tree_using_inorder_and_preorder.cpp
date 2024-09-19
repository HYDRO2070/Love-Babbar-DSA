#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *left,*right;
    Node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};
void postorder(Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}
void inoder(Node *root){
    if(root != NULL){
        inoder(root->left);
        cout<<root->val<<" ";
        inoder(root->right);
    }
}

void createmap(vector<int> &in,map<int,int> &m){
    for(int i = 0;i < in.size();i++){
        m[in[i]] = i;
    }
}

Node* solve(vector<int> &in,vector<int> &pre,map<int,int> &m,int s,int e,int &cnt){
    if(cnt >= pre.size() || (s > e)) return NULL;
    Node *root = new Node(pre[cnt]);
    int index = m[pre[cnt++]];
    // cout<<pre[cnt]<<" "<<index<<endl;
    // cout<<s<<" "<<e<<" "<<cnt<<endl;
    root->left = solve(in,pre,m,s,index-1,cnt);
    root->right = solve(in,pre,m,index+1,e,cnt);
    return root;
}

Node* construct(vector<int> &in,vector<int> &pre){
    int cnt = 0;
    map<int,int> m;
    createmap(in,m);
    return solve(in,pre,m,0,in.size()-1,cnt);
}

int main(){
    // int in[4] = {1,6,8,7};
  // int pre[4] = {1,6,7,8};
    vector<int> in;
    in.push_back(3);
    in.push_back(1);
    in.push_back(4);
    in.push_back(0);
    in.push_back(5);
    in.push_back(2);
    vector<int> pre;
    pre.push_back(0);
    pre.push_back(1);
    pre.push_back(3);
    pre.push_back(4);
    pre.push_back(2);
    pre.push_back(5);
    Node * root = (construct(in,pre));
    inoder(root);
    cout<<endl;
    postorder(root);
    return 0;
}