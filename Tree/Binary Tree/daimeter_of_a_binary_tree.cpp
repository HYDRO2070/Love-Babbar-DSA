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

// int height(Node *root){
//     cout<<"hello"<<endl;
//     if(root == NULL) return 0;
//     int left = height(root->left);
//     int right = height(root->right);
//     return max(left,right)+1;
// }

// It is Not optimize. O(n2)
// int daimeter(Node *root){
//     cout<<"hello"<<endl;
//     if(root == NULL) return 0;
//     int op1 = daimeter(root->left);
//     int op2 = daimeter(root->right);
//     int op3 = height(root->left) + height(root->right)+1;
//     return max(max(op1,op2),op3);
//  }

pair<int,int> daimeter(Node *root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = daimeter(root->left);
    pair<int,int> right = daimeter(root->right);
    int ans = max(left.first,max(right.first,left.second+right.second+1));
    return make_pair(ans,max(left.second,right.second)+1);
}

// optimize code of O(n)
int solve(Node *root){
    pair<int,int> ans = daimeter(root);
    return ans.first;
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
    cout<<endl<<solve(root);
    
    return 0;
}