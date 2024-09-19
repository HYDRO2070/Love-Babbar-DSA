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
void inoderr(Node *root,vector<int> &arr){
    if(root != NULL){
        inoderr(root->left,arr);
        arr.push_back(root->val);
        inoderr(root->right,arr);
    }
}

void place(Node *root,vector<int> &arr,int &i){
    if(root == NULL) return;
    root->val = arr[i++];
    place(root->left,arr,i);
    place(root->right,arr,i);
}

Node* convert(Node *root){
    vector<int> in;
    inoderr(root,in);
    int i = 0;
    place(root,in,i);
    return root;
}


int main(){
    // //              4
    //         2               6
    //     1        3      5       7
    //                      


    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    inoder(root);
    cout<<endl;
    
    inoder(convert(root));
    return 0;
}