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
    return make_pair(root->val+left.second+right.second,max(left.first,left.second) + max(right.first,right.second));
}

int max_sum(Node *root){
    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
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
    cout<<max_sum(root)<<endl;
    return 0;
}