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

Node* find(Node *root){
    Node *temp = root;
    root = root->left;
    while(root->right && root->right != temp)
    root = root->right;
    return root;
}

bool twosum(Node *root,int val){
    vector<int> m;
    Node *temp = root;
    while(root != NULL){
        if(!root->left){
            m.push_back(root->val);
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
                m.push_back(root->val);
                root = root->right;
            }
        }
    }
    int i = 0;
    int j = m.size()-1;
    while(i < j){
        int sum = m[i] + m[j];
        if(sum == val) return true;
        else if(sum > val) j--;
        else i++;
    }
    return false;
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
    cout<<twosum(root,40);
    return 0;
}