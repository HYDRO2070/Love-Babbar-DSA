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

void printleft(Node *root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    cout<<root->val<<" ";
    if(root->left) printleft(root->left);
    else printleft(root->right);
}
void printleaf(Node *root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        cout<<root->val<<" ";
        return;
    }
    printleaf(root->left);
    printleaf(root->right);
}

void printright(Node *root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    if(root->right) printright(root->right);
    else printright(root->left);
    cout<<root->val<<" ";
}

// void boundary(Node *root){

// }
int main(){
    //              1
    //     2              5
    // 3      4         6    7
    //          9             8
            //    10


    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(9);
    root->left->right->right->right = new Node(10);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    inoder(root);
    cout<<endl;
    printleft(root);
    printleaf(root);
    printright(root->right);
    return 0;
}