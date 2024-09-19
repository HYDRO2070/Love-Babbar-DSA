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


bool identical(Node *root,Node *head){
    if(root == NULL && head == NULL) return true;
    if(root == NULL && head != NULL) return false;
    if(root != NULL && head == NULL) return false;
    bool temp = root->val == head->val;
    if(!temp) return false;
    bool left = identical(root->left,head->left);
    bool right = identical(root->right,head->right);
    return (temp && left && right);
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
    Node *head = new Node(1);
    head->left = new Node(2);
    head->left->left = new Node(3);
    head->left->right = new Node(4);
    head->left->right->right = new Node(9);
    head->left->right->right->right = new Node(10);
    head->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    head->right->right->right = new Node(8);
    inoder(root);
    cout<<endl;
    cout<<identical(root,head);
    return 0;
}