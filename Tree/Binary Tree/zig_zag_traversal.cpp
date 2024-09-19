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

void zig_zag(Node *root){
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    bool  flag = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> a(size);
        for(int i = 0; i < size;i++){
            Node *temp = q.front();
            q.pop();
            int index = flag ? i : size-i-1;
            a[index] = temp->val;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        flag = !flag;
        for(int i = 0;i<a.size();i++){
            ans.push_back(a[i]);
        }

    }
    for(int i =0 ;i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
    zig_zag(root);
    return 0;
}