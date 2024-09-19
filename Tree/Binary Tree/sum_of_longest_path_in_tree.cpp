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

pair<int,int> solve(Node *root){
    if(root == NULL) return make_pair(0,0);
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);
    int sum = root->val;
    int h = 0;
    if(left.first < right.first){
        h = right.first;
        sum += right.second;
    }
    else if(left.first > right.first){
        h = left.first;
        sum += left.second;
    }
    else{
        h = left.first;
        sum += max(left.second,right.second);
    }
    return make_pair(h+1,sum);
}

int main(){
    // //              1
    //         2               3
    //     4        5      6       7
    //                         8      9


    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    // root->left->right->right->right = new Node(10);
    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    // root->right->left->right = new Node(8);
    // root->right->right->right = new Node(9);
    inoder(root);
    cout<<endl;
    cout<<solve(root).second<<endl;
    return 0;
}