#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *left,*right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

void inorder(Node *root){
    if(root == NULL) return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

Node* pushnode(Node *root,int val){
    // cout<<"Hello"<<endl;
    if(root == NULL){
        return new Node(val);
    }
    if(root->val > val){
        root->left = pushnode(root->left,val);
    }
    else{
        root->right = pushnode(root->right,val);
    }
    return root;
}

Node* create_bst(int *arr,int n){
    Node *root = NULL;
    for(int i = 0;i < n;i++){
        root = pushnode(root,arr[i]);
    }
    return root;
}

void inord(Node *root,vector<Node*> &m){
    if(root == NULL) return;
    inord(root->left,m);
    m.push_back(root);
    inord(root->right,m);
}

Node* fallten(Node *root){
    vector<Node*> m;
    inord(root,m);
    for(int i = 0;i < m.size()-1;i++){
        m[i]->left = NULL;
        m[i]->right = m[i+1];
    }
    m[m.size()-1]->left = m[m.size()-1]->right = NULL;
    return m[0];
}

int main(){
//                 10
//             8        21
//           7   9          27
//       5
//    4
// 3


    int arr[9] = {10,8,21,7,27,5,4,3,9};
    Node *root = create_bst(arr,9);
    inorder(root);
    cout<<endl;
    inorder(fallten(root));
    return 0;
}