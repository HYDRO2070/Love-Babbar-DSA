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

// recursive way
// bool search_in_tree(Node *root,int val){
//     if(root == NULL) return false;
//     if(root->val == val) return true;
//     if(root->val < val){
//         return search_in_tree(root->right,val);
//     }
//     return search_in_tree(root->left,val);
// }

// itrative way
bool search_in_tree(Node *root,int val){
    while(root != NULL){
        if(root->val == val) return true;
        if(root->val < val){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return false;
}


int main(){
    int arr[8] = {10,8,21,7,27,5,4,3};
    Node *root = create_bst(arr,8);
    inorder(root);
    cout<<endl;
    cout<<search_in_tree(root,27);
    return 0;
}