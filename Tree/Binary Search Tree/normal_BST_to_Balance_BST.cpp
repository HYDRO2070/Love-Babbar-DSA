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

pair<int,bool> balance_BST(Node *root){
    // cout<<"Hello"<<endl;
    if(root == NULL) return {0,true};
    pair<int,bool> left = balance_BST(root->left);
    pair<int,bool> right = balance_BST(root->right);
    bool temp = (abs(left.first - right.first) <= 1);
    return {(max(left.first,right.first)+1),(left.second && right.second && temp)};
}

Node * create_bts(vector<int> &arr,int i,int j){
    cout<<"World"<<endl;
    if(i > j) return NULL;
    int mid = i + (j - i) / 2;
    Node *newroot = new Node(arr[mid]);
    newroot->left = create_bts(arr,i,mid-1);
    newroot->right = create_bts(arr,mid+1,j);
    return newroot;
}


Node* create_bala(Node *root){
    if(balance_BST(root).second) return root;
    vector<int> arr;
    Node *temp = root;
    while(temp != NULL){
        cout<<"hello"<<endl;
        if(!temp->left){
            arr.push_back(temp->val);
            temp = temp->right;
        }
        else{
            Node *pre = find(temp);
            if(pre->right){
                pre->right = NULL;
                temp = temp->right;
            }
            else{
                pre->right = temp;
                arr.push_back(temp->val);
                temp = temp->left;
            }
        }
    }
    int i = 0;
    int j = arr.size() - 1;
    return create_bts(arr,i,j);
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
    cout<<balance_BST(root).second<<endl;
    Node *newroot = create_bala(root);
    cout<<balance_BST(newroot).second;
    
    return 0;
}