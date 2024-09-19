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


bool isbal(Node *root){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    // cout<<"Hello "<<root->val<<endl;
    bool left = isbal(root->left);
    bool right = isbal(root->right);
    bool temp = true;
    if(root->left) temp = (root->val > root->left->val);
    if(root->right) temp = (root->val > root->right->val);
    return left && right && temp;

}

bool iscbt(Node *root,int i,int cnt){
    // if(root == NULL) return false;
    // if(root->left == NULL && root->right == NULL) return true;
    // bool left = iscbt(root->left);
    // bool right = iscbt(root->right);
    
    // return left && right;
    if(root == NULL) return true;
    if(i > cnt) return false;
    else{
        bool left = iscbt(root->left,2*i+1,cnt); 
        bool right = iscbt(root->right,2*i+2,cnt); 
        return left && right;
    }
}

void count(Node *root,int &cnt){
    if(root == NULL) return;
    count(root->left,cnt);
    cnt++;
    count(root->right,cnt);
}

bool isheap(Node *root){
    int cnt = 0;
    count(root,cnt);
    return iscbt(root,0,cnt-1) && isbal(root);
}

int main(){
    // //              1
    //         2               3
    //     4        5      6       7
    //                         8      9


    Node *root = new Node(100);
    root->left = new Node(20);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(2);
    // root->left->right->right = new Node(9);
    // root->left->right->right->right = new Node(10);
    root->right = new Node(30);
    root->right->left = new Node(16);
    root->right->right = new Node(17);
    // root->right->left->right = new Node(8);
    // root->right->right->right = new Node(9);
    inoder(root);
    cout<<endl;
    cout<<isheap(root);
    return 0;
}