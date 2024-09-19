// basic Term used in tree - Node,root,children,parent,siblings,ancustor,descendent,leaf
// Non-Linear data structure

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
// 1 2 3 4 5 6 7 4 2 6 1 3 5 7
Node* build(Node *root){
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;
    if(data == -1) return NULL;
    root = new Node(data);

    cout<<"Left : "<<data<<endl;
    root->left = build(root->left);
    cout<<"right "<<data<<" :"<<endl;
    root->right = build(root->left);
    return root;
}

void inoder(Node *root){
    if(root != NULL){
        inoder(root->left);
        cout<<root->val<<" ";
        inoder(root->right);
    }
}

void preoder(Node *root){
    if(root != NULL){
        cout<<root->val<<" ";
        inoder(root->left);
        inoder(root->right);
    }
}

void postoder(Node *root){
    if(root != NULL){
        inoder(root->left);
        inoder(root->right);
        cout<<root->val<<" ";
    }
}

void levelorder(Node *root){
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    q.push(NULL);

    // level order traversal
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            s.push(NULL);
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->val<<" ";
            s.push(temp);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    s.pop();
    // reverse level order traversal
    while (!s.empty())    {
        if(s.top() == NULL){
            cout<<endl;
        }
        else{
            cout<<s.top()->val<<" ";
        }
        s.pop();
    }
}


int main(){
    Node *root = NULL;
    root = build(root);
    inoder(root);
    cout<<endl;
    preoder(root);
    cout<<endl;
    postoder(root);
    cout<<endl;
    levelorder(root);
    return 0;
}