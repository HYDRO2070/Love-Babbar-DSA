#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *left,*right;
    Node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};
void inoder(Node *root){
    if(root != NULL){
        inoder(root->left);
        cout<<root->val<<" ";
        inoder(root->right);
    }
}



int kth_an(Node *root,int &k,int n){
    if(root == NULL) return 0;
    if(root->val == n) return root->val;
    int left = kth_an(root->left,k,n);
    int right = kth_an(root->right,k,n);
    if(!left && !right) return 0;
    if(left || right){
        k--;
    }
    if(k == 0) return root->val;
    if(left) return left;
    return right;
}

int main(){
            //              9
    //             3                -1
    //       11         8       4           5
    //               7      1      2           6


    Node *root = new Node(9);
    root->left = new Node(3);
    root->left->left = new Node(11);
    root->left->right = new Node(8);
    root->left->right->left = new Node(7);

    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);
    inoder(root);
    cout<<endl;
    int k = 2;
    cout<<kth_an(root,k,9);
    return 0;
}