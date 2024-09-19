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

void inorder(Node *root){
    if(root == NULL) return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void inorder(Node *root,vector<int> &a){
    if(root == NULL) return ;
    inorder(root->left,a);
    a.push_back(root->val);
    inorder(root->right,a);
}

void merge(vector<int> &f,vector<int> &s,vector<int> &ans){
    int i = 0,j = 0;
    int imax = f.size();
    int jmax = s.size();
    while(i < imax && j < jmax){
        if(f[i] < s[j]){ 
        ans.push_back(f[i]);
        i++;
        }
        else{ 
            ans.push_back(s[j]);
            j++;
            }
    }
    while(i < imax){
  
        ans.push_back(f[i]);
        i++;
    }
    while(j < jmax){
  
        ans.push_back(s[j]);
        j++;
    }
}

Node * create_bts(vector<int> &arr,int i,int j){
    // cout<<"World"<<endl;
    if(i > j) return NULL;
    int mid = i + (j - i) / 2;
    Node *newroot = new Node(arr[mid]);
    newroot->left = create_bts(arr,i,mid-1);
    newroot->right = create_bts(arr,mid+1,j);
    return newroot;
}

Node* solve(Node *root,Node *head){
    vector<int> first;
    vector<int> second;
    inorder(root,first);
    inorder(head,second);
    vector<int> ans;
    merge(first,second,ans);
    // for(int i = 0;i <ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    return create_bts(ans,0,ans.size()-1);
}



int main(){
//                 10
//             8        21
//           7   9          27
//       5
//    4
// 3

// 3 4 5 7 8 9 10 21 27 
    int arr[9] = {10,8,21,7,27,5,4,3,9};
    Node *root = create_bst(arr,9);
    inorder(root);
    cout<<endl;
    int arr1[9] = {14,87,90,45,12,54,17,22,21};
    Node *head = create_bst(arr1,9);
    inorder(head);
    cout<<endl;
    Node *ans = solve(root,head);
    inorder(ans);
    cout<<endl;
    return 0;
}