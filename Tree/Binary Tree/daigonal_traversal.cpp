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
void inoder(Node *root){
    if(root != NULL){
        inoder(root->left);
        cout<<root->val<<" ";
        inoder(root->right);
    }
}

int leftval(Node *root){
    if(root == NULL) return +1;
    return leftval(root->left) - 1;
}
int rightval(Node *root){
    if(root == NULL) return 0;
    return rightval(root->left) + 1;
}


int solve(Node *root){
    if(root == NULL) return 1;
    return solve(root->left) - 1;
}



vector<int> daigonal(Node *root){
    map<int,vector<int> > m;
    queue<pair<Node*,int> > q;
    vector<int> ans;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        m[temp.second].push_back(temp.first->val);
        // cout<<temp.second<<" "<<temp.first->val<<endl;
        if(temp.first->left)
        q.push(make_pair(temp.first->left,temp.second-1));
        if(temp.first->right)
        q.push(make_pair(temp.first->right,temp.second));
    }
    int l = solve(root);
    for(int i = 0; i >= l;i--){
        for(int j = 0;j < m[i].size();j++){
            ans.push_back(m[i][j]);
        }
    }
    return ans;
}

int main(){
    // //              1
    //         2               3
    //     4        5      6       7
    //                         8      9


    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->left->right->right = new Node(9);
    // root->left->right->right->right = new Node(10);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    inoder(root);
    cout<<endl;
    vector<int> ans = daigonal(root);
    for(int i = 0; i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}