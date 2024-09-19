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

void solve(Node *root,int k,vector<int> &path,int &cnt){
    if(root == NULL) return;
    path.push_back(root->val);
    solve(root->left,k,path,cnt);
    solve(root->right,k,path,cnt);
    int sum = 0;
    for(int i = path.size()-1;i >= 0;i--){
        sum += path[i];
        if(sum == k) cnt++;
    }
    path.pop_back();
}

int count_path(Node *root,int k){
    vector<int> path;
    int cnt = 0;
    solve(root,k,path,cnt);
    return cnt;
}

int main(){
            //              1
    //             3                -1
    //       2         1       4           5
    //               1      1      2           6


    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);

    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);
    inoder(root);
    cout<<endl;
    cout<<count_path(root,5);
    return 0;
}