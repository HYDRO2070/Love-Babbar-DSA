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

// to find the path from root node to any node
// void solve(Node *root,vector<int> &a,int &flag,int num){
//     if(root == NULL) return;
//     if(root->val == num){
//         a.push_back(root->val);
//         flag = 1;
//         return;
//     }
//     if(flag!=1){
//         solve(root->left,a,flag,num);
//         if(flag!=1)
//         solve(root->right,a,flag,num);
//     }
//     if(flag == 1){
//         a.push_back(root->val);
//     }
// }

Node* lca(Node *root,int n1,int n2){
    if(root == NULL) return NULL;
    if(root->val == n1 || root->val == n2) return root;
    Node *left = lca(root->left,n1,n2);
    Node *right = lca(root->right,n1,n2);
    if(!left && !right) return NULL;
    if(left && !right) return left;
    if(!left && right) return right;
    if(left && right) return root;
}

int main(){
    // //              4
    //         2               5
    //     7        1      2       3
    //            6          


    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    inoder(root);
    cout<<endl;
    cout<<lca(root,6,3)->val;
    return 0;
}