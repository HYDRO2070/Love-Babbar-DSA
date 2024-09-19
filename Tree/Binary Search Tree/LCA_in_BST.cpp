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

// recursion
// Node* LCA(Node *root,int a,int b){
//     if(root == NULL) return NULL;
    
//     if(root->val < a && root->val < b){
//         return LCA(root->right,a,b);
//     }
//     if(root->val > a && root->val > b){
//         return LCA(root->left,a,b);
//     }
//     return root;
// }


Node* LCA(Node *root,int a,int b){
    if(root == NULL) return NULL;
    
    while(root != NULL){
        if(root->val < a && root->val < b){
            root = root->right;
        }
        else if(root->val > a && root->val > b){
            root = root->left;
        }
        else{
            return root;
        }
    }
}

int main(){
//                 10
//             8        21
//           7   9          27
//       5
//    4
// 3
    int arr[8] = {10,8,21,7,27,5,4,3};
    Node *root = create_bst(arr,8);
    inorder(root);
    cout<<endl;
    cout<<LCA(root,5,7)->val;
    return 0;
}