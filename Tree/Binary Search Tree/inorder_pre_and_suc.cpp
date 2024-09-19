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

// void inorder_pre(Node *root,Node *&pre,int val,int &a){
//     if(root == NULL) return;
//     if(root->val == val){
//         a = pre->val;
//         return;
//     }
    
//     inorder_pre(root->left,pre,val,a);
//     pre = root;
//     inorder_pre(root->right,pre,val,a);

// }

pair<int,int> solve(Node *root,int val){
    Node *temp = root;
    int pre = -1;
    int suc = -1;
    while(root->val != val){
        if(root->val < val){
            pre = root->val;
            root = root->right;
        }
        else{
            suc = root->val;
            root = root->left;
        }
    // cout<<"jee"<<endl;
    }
    Node *left = root->left;
    Node *right = root->right;
    while(left != NULL){
        pre = left->val;
        left = left->right;
    }
    while(right != NULL){
        suc = right->val;
        right = right->left;
    }
    return make_pair(pre,suc);
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
    // Node *pre = NULL;
    // int a = 0;
    // inorder_pre(root,pre,8,a);
    // cout<<a;
    pair<int,int> ans = solve(root,10);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}