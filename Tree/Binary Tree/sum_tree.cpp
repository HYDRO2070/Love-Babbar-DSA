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


pair<bool,int> sumtree(Node *root){
    if(root == NULL) return make_pair(true,0);
    if(root->left == NULL && root->right == NULL) return make_pair(true,root->val);
    pair<bool,int> left = sumtree(root->left);
    pair<bool,int> right = sumtree(root->right);
    
    if(left.first && right.first && (root->val == left.second + right.second))
    return make_pair(true,2*root->val);
    return make_pair(false,0);

}

int main(){
    //              1
    //     2              5
    // 3      4         6    7
    //          9             8
            //    10


    Node *root = new Node(16);
    root->left = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->left->right->right = new Node(1);
    root->left->right->right->right = new Node(1);
    root->right = new Node(3);
    root->right->left = new Node(1);
    root->right->right = new Node(1);
    root->right->right->right = new Node(1);
    inoder(root);
    cout<<endl;
    cout<<sumtree(root).first;
    return 0;
}