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

void solve(Node *root,vector<int> &ans,int lvl){
    if(root == NULL) return;
    if(lvl == ans.size()) ans.push_back(root->val);
    solve(root->left,ans,lvl+1);
    solve(root->right,ans,lvl+1);
}

vector<int> left_view(Node *root){
    // queue<Node*> q;
    vector<int> ans;
    // Node *pre = root;
    // q.push(root);
    // q.push(NULL);
    // ans.push_back(root->val);
    // while(!q.empty()){
    //     Node *temp = q.front();
    //     q.pop();
    //     if(temp == NULL){
    //         if(!q.empty()) q.push(NULL);
    //     }
    //     else{
    //         if(pre == NULL) ans.push_back(temp->val);
    //         if(temp->left) q.push(temp->left);
    //         if(temp->right) q.push(temp->right);
    //     }
    //     pre = temp;
    // }


    // second method using recursion
    solve(root,ans,0);
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
    vector<int> ans = left_view(root);
    for(int i = 0; i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}