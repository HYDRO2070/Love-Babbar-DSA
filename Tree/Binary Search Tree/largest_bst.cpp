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

class info{
    public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};

void inoder(Node *root){
    if(root != NULL){
        inoder(root->left);
        cout<<root->val<<" ";
        inoder(root->right);
    }
}

info la_bst(Node *root,int &mast){
    if(root == NULL) return {INT_MIN,INT_MAX,true,0};
    info left = la_bst(root->left,mast);
    info right = la_bst(root->right,mast);
    info ans;
    ans.size = left.size + right.size + 1;
    ans.maxi = max(root->val,right.maxi);
    ans.mini = min(root->val,left.mini);
    ans.isbst = (left.isbst && right.isbst && (root->val > left.maxi && root->val < right.mini));
    if(ans.isbst) mast = max(mast,ans.size);
    return ans;

}

int solve(Node *root){
    int ans = 0;
    info temp = la_bst(root,ans);
    return ans;
}

int main(){
    // //              1
    //         2               3
    //     4        5      6       7
    //                         8      9


    Node *root = new Node(5);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(4);
    inoder(root);
    cout<<endl;
    cout<<solve(root);
    return 0;
}