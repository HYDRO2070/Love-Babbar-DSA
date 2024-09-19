

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

void build(Node *&root){
    queue<Node*> q;
    cout<<"Enter The Data :"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        int left,right;
        cout<<"Left of "<<temp->val<<endl;
        cin>>left;
        if(left != -1){
            temp->left = new Node(left);
            q.push(temp->left);
        }
        cout<<"right of "<<temp->val<<endl;
        cin>>right;
        if(right != -1){
            temp->right = new Node(right);
            q.push(temp->right);
        }
    }
}

int main(){
    Node *root = NULL;
    build(root);
    inoder(root);
    

    
    return 0;
}