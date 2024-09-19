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

pair<bool,int> isbalance(Node *root){
    if(root == NULL) return make_pair(true,0);
    pair<bool,int> left = isbalance(root->left);
    pair<bool,int> right = isbalance(root->right);
    int h = max(left.second , right.second) + 1;
    if(left.first && right.first && abs(left.second - right.second) <= 1){
        return make_pair(true,h);
    }
    return make_pair(false,h);
}

bool isbal(Node *root){
    return isbalance(root).first;
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
    cout<<endl<<isbal(root);
    return 0;
}