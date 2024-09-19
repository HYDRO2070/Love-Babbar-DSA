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
void preorder(Node *root){
    if(root != NULL){
        preorder(root->left);
        preorder(root->right);
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

Node* solve(vector<int> &in,vector<int> &post,map<int,int> &m,int s,int e,int &cnt){
    if(cnt < 0 || (s > e)) return NULL;
    Node *root = new Node(post[cnt]);
    int index = m[post[cnt--]];
    // cout<<post[cnt]<<" "<<index<<endl;
    // cout<<s<<" "<<e<<" "<<cnt<<endl;

    // left right node
    root->right = solve(in,post,m,index+1,e,cnt);
    root->left = solve(in,post,m,s,index-1,cnt);
    return root;
}

Node* construct(vector<int> &in,vector<int> &post){
    int cnt = post.size()-1;
    map<int,int> m;
    createmap(in,m);
    return solve(in,post,m,0,in.size()-1,cnt);
}

int main(){
    // int in[4] = {1,6,8,7};
  // int post[4] = {1,6,7,8};
    vector<int> in;
    in.push_back(4);
    in.push_back(8);
    in.push_back(2);
    in.push_back(5);
    in.push_back(1);
    in.push_back(6);
    in.push_back(3);
    in.push_back(7);
    vector<int> post;
    post.push_back(8);
    post.push_back(4);
    post.push_back(5);
    post.push_back(2);
    post.push_back(6);
    post.push_back(7);
    post.push_back(3);
    post.push_back(1);
    Node * root = (construct(in,post));
    inoder(root);
    cout<<endl;
    preorder(root);
    return 0;
}