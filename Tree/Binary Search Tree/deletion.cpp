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

int find(Node *root){
    if(root->right == NULL) return root->val;
    return find(root->right);
}

Node* deletenode(Node *root,int val){
    if(root == NULL) return root;
    if(root->val == val){
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
    
        if(root->left && !root->right){
            Node *temp = root->left;
            root->left = NULL;
            delete root;
            return temp;
        }
        if(!root->left && root->right){
            Node *temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        }
        if(root->left && root->right){
            int maxi = find(root->left);
            cout<<maxi<<endl;
            root->val = maxi;
            root->left = deletenode(root->left,maxi);
            return root;
        }
    }
    else if(root->val < val){
        root->right = deletenode(root->right,val);
        return root;
    }
    root->left = deletenode(root->left,val);
    return root;
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
    inorder(deletenode(root,8));
    return 0;
}