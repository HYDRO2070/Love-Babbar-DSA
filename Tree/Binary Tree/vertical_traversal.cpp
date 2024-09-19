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

vector<int> vertical(Node *root){
    map<int,map<int,vector<int> > > nodes;
    queue<pair<Node* , pair<int,int> > > q;
    vector<int> ans;
    if(root == NULL) return ans;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<Node*,pair<int,int> > temp = q.front();
        q.pop();
        cout<<temp.second.first<<" "<<temp.second.second<<" "<<temp.first->val<<endl;
        nodes[temp.second.first][temp.second.second].push_back(temp.first->val);
        if(temp.first->left)
        q.push(make_pair(temp.first->left,make_pair(temp.second.first-1,temp.second.second+1)));
        if(temp.first->right)
        q.push(make_pair(temp.first->right,make_pair(temp.second.first+1,temp.second.second+1)));
    }
    cout<<nodes[-1][1][0]<<endl;
    // int s1 = nodes.size();
    // for(int i = -2;i < 4;i++){
    //     map<int,vector<int> >temp1 = nodes[i];
    //     int s2 = temp1.size();
    //     // cout<<"hello Wolrd"<<i<<endl;
    //     // cout<<nodes[i][i][i]<<endl;
    //     for(int j = 0;j < s2;j++){
    //         vector<int> temp3 = temp1[j];
    //         for(int k = 0;k < temp3.size();k++){
    //             cout<<temp3[k]<<" ";
    //         }
    //         cout<<"-----"<<endl;
    //     }
    // }
    // cout<<nodes.size()<<endl;
    // cout<<nodes[0].size()<<endl;
    // cout<<nodes[0][0][0]<<endl;
    return ans;
}

int main(){
    //              1
    //     2              5
    // 3      4         6    7
    //          9             8
            //    10


    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->left->right->right = new Node(9);
    // root->left->right->right->right = new Node(10);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    inoder(root);
    cout<<endl;
    vector<int> ans = vertical(root);
    for(int i = 0; i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}