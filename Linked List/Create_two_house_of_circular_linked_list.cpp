// we have been given a circular linked list and we have to split it into two part. both of them will be circular itself.


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void printlist(Node *head){
    Node *temp = head;
    
    cout<<head->val<<" ";
    head = head->next;
    while(head != temp && head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}


void deletelist(Node *head){
    Node *temp = head;
    
    Node *temp1 = head;
    head = head->next;
    temp1->next = NULL;
    free(temp);
    while(head != temp && head != NULL){
        Node *temp1 = head;
        head = head->next;
        temp1->next = NULL;
        free(temp);
    }
    cout<<endl;
    temp->next = NULL;
    delete temp;
}

void InsertatEnd(Node *head,int val){
    Node *n = new Node(val);
    if(head->next == NULL){

        cout<<"jejej"<<endl;
        head->next = n;
        n->next = head;
        return;
    }
    Node *temp = head;

    head = head->next;
    while(head->next != temp && head != NULL){
        head = head->next;
    }
    head->next = n;
    n->next = temp;
}

void splitlist(Node *head,vector<Node*> &ans){
    ans.push_back(head);
    if(head == NULL || head->next == NULL){
        return;
    }
    Node *temp = head;
    Node *pre = head;
    while(head->next != temp){
        head = head->next;
        if(head->next != temp){ 
            head = head->next;
            pre = pre->next;
        }
    }
    ans.push_back(pre->next);
    pre->next = temp;
    head = ans[1];
    while(head->next != temp){
        head = head->next;
    }
    head->next = ans[1];


    // cout<<pre->val<<endl;
    // cout<<head->val<<endl;
}

int main(){
    
    Node *head = new Node(1);
    vector<Node*> ans;
    head->next = head;
    InsertatEnd(head,8);
    // InsertatEnd(head,7);
    // InsertatEnd(head,6);
    // InsertatEnd(head,9);
    // InsertatEnd(head,99);
    printlist(head);
    splitlist(head,ans);
    printlist(ans[0]);
    printlist(ans[1]);

    deletelist(head);
    return 0;
}