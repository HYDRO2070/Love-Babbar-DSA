#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

class compare{
    public:
    bool operator()(Node *a,Node *b){
        return a->data > b->data;
    }
};


void print(Node *root){
    while(root != NULL){
        cout<<root->data<<" ";
        root = root->next;
    }
    cout<<endl;
}


Node* mergeall(vector<Node*> nodes){
    priority_queue<Node*,vector<Node*>,compare> pq;
    Node *head = NULL;
    Node *tail = NULL;
    for(int i = 0;i < nodes.size();i++){
        if(nodes[i] != NULL)
        pq.push(nodes[i]);
    }

    while(!pq.empty()){
        // cout<<"Hello"<<endl;
        Node *temp = pq.top();
        pq.pop();
        if(head == NULL && tail == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
            // temp->next = NULL;
        }
        if(temp->next){
            pq.push(temp->next);
        }
    }
    // tail->next = NULL;
    return head;
}

int main(){
    vector<Node*> nodes;
    Node *h1 = new Node(1);
    h1->next = new Node(5);
    h1->next->next = new Node(8);
    h1->next->next->next = new Node(9);
    Node *h2 = new Node(2);
     h2->next = new Node(4);
    h2->next->next = new Node(10);
    h2->next->next->next = new Node(14);
    Node *h3= new Node(12);
     h3->next = new Node(15);
    h3->next->next = new Node(18);
    h3->next->next->next = new Node(20);
    nodes.push_back(h1);
    nodes.push_back(h2);
    nodes.push_back(h3);

    print(mergeall(nodes));


    return 0;
}