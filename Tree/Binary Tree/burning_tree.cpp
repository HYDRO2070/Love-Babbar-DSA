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

Node* create_map(Node *root,map<Node*,Node*> &m,int t){
    Node *ans = NULL;
    queue<Node*> q;
    q.push(root);
    m[root] = NULL;
    while(!q.empty()){
        
        // cout<<"Hello1"<<endl;
        Node *temp = q.front();
        q.pop();
        if(temp->val == t) ans = temp;
        if(temp->left){
            m[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right){
            m[temp->right] = temp;
            q.push(temp->right);
        }
    }
        return ans;
    
}

void burntree(Node *root,map<Node*,Node*> &m,int &time){
    map<Node*,bool> visited;
    queue<Node*> q;
    q.push(root);
    visited[root] = true;
    while(!q.empty()){
        // cout<<"Hello"<<endl;
        bool flag = 0;
        int size = q.size();
        for(int i = 0;i < size;i++){
            Node *temp = q.front();
            cout<<temp->val<<endl;
            q.pop();
            if(temp->left && !visited[temp->left]){
                visited[temp->left] = true;
                flag = 1;
                q.push(temp->left);
            }
            if(temp->right && !visited[temp->right]){
                visited[temp->right] = true;
                flag = 1;
                q.push(temp->right);
            }
            if(m[temp] && !visited[m[temp]]){
                visited[m[temp]] = true;
                flag = 1;
                q.push(m[temp]);
            }
        }
        if(flag == 1) time++;
    }
}

int solve(Node *root,int t){
    int time = 0;
    map<Node*,Node*> m;
    
    burntree(create_map(root,m,t),m,time);
    return time;
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
    cout<<solve(root,10);
    return 0;
}