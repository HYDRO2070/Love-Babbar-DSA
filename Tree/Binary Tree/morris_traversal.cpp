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

Node* find(Node *root){
    Node *temp = root;
    root = root->left;
    while(root->right != NULL && root->right != temp){
        root = root->right;
    }
    return root;
}

void morris_traversal(Node *root){
    while(root != NULL){
        // cout<<"Heloek"<<endl;
        if(!root->left){
            cout<<root->val<<" ";
            root = root->right;
        }
        else{
            Node *pre = find(root);
            if(pre->right == NULL){
                pre->right = root;
                root = root->left;
            }
            else{
                pre->right = NULL;
                cout<<root->val<<" ";
                root = root->right;
            }
        }
    }
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
    morris_traversal(root);
    return 0;
}