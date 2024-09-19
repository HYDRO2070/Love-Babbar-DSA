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

// Node* create_BSt(int *arr,int i,int j){
//     if(i > j) return NULL;
//     Node *root = new Node(arr[i]);
//     int mid = i+1;
//     while(arr[i] > arr[mid])
//     mid++;
//     root->left = create_BSt(arr,i+1,mid-1);
//     root->right = create_BSt(arr,mid,j);
//     return root;
// }

Node* create_bst(int *arr,int mini,int maxi,int &i,int &s){

    // cout<<"Hello "<<mini<<" "<<maxi<<" "<<arr[i]<<endl;
    if(i >= s) return NULL;
    if(arr[i] < mini || arr[i] > maxi) return NULL;
    Node *root = new Node(arr[i++]);
    root->left = create_bst(arr,mini,root->val,i,s);
    root->right = create_bst(arr,root->val,maxi,i,s);
    return root;
}

int main(){
//                 10
//             8        21
//           7   9          27
//       5
//    4
// 3

// 3 4 5 7 8 9 10 21 27 
    int arr[9] = {10,8,7,5,4,3,9,21,27};
    int i = 0,s = 9;
    inorder(create_bst(arr,INT_MIN,INT_MAX,i,s));
    return 0;
}