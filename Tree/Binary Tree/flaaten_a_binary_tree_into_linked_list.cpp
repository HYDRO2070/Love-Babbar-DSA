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

void traversal(Node *root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    traversal(root->right);
}

void flatten(Node *root){
    Node *curr = root;
    while(curr != NULL){
        // cout<<1<<endl;
        if(curr->left){
            Node *pre = curr->left;
            while(pre->right)
            pre = pre->right;
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    traversal(root);
}

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
    flatten(root);
    return 0;
}