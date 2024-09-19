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


// inorder mentod
// void kth_small(Node *root,int &n,int &ans){
//     if(root == NULL) return;
//     kth_small(root->left,n,ans);
//     n--;
//     cout<<n<<endl;
//     if(n == 0){
//         ans = root->val;
//     }
//     kth_small(root->right,n,ans);
// }

Node* find(Node *root){
    Node *temp = root;
    root = root->left;
    while(root->right && root->right != temp)
    root = root->right;
    return root;
}

void kth_small(Node *root,int &n,int &ans){
    while(root != NULL){
        if(!root->left){
            if(--n == 0){ 
                ans = root->val;
                break;
            }
            root = root->right;
        }
        else{
            Node *pre = find(root);
            if(!pre->right){
                pre->right = root;
                root = root->left;
            }
            else{
                pre->right = NULL;
                if(--n == 0){ 
                    ans = root->val;
                    break;
                }
                root = root->right;
            }

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


    int arr[9] = {10,8,21,7,27,5,4,3,9};
    Node *root = create_bst(arr,9);
    inorder(root);
    cout<<endl;
    int a = 4;
    int ans = 0;
    kth_small(root,a,ans);
    cout<<ans;
    return 0;
}