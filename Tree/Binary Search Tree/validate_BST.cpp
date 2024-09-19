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


bool isBST(Node *root,pair<int,int> t){
    cout<<"Hello"<<endl;
    if(root == NULL) return true;
    if(root->val < t.first || root->val > t.second) return false;
    bool left = isBST(root->left,make_pair(t.first,root->val));
    bool right = isBST(root->right,make_pair(root->val,t.second));
    return (left && right);

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
    cout<<isBST(root,make_pair(INT_MIN,INT_MAX));
    return 0;
}