// linked list is a type of datastructer which is collection of nodes.
// node have two value which are value and pointer to the next node.

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
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* insertatStart(Node *head,int val){
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;

}

void insertatEnd(Node *head,int val){
    Node *temp = new Node(val);
    while(head->next != NULL){
        head = head->next;
    }
    head->next = temp;

}

void insertatMiddle(Node *head,int val,int pos){
    if(pos == 1){
        insertatStart(head,val);
        return;
    }
    int cnt = 1;
    Node *temp = new Node(val);
    while(cnt < pos && head->next != NULL){
        head = head->next;
        cnt++;
    }
    temp->next = head->next;
    head->next = temp;
}

void deletelist(Node *head){
    while (head != NULL){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    
}

int main(){
    Node *head = new Node(5);
    // a->val = 9;
    // cout<<a->val;
    printlist(head);
    head = insertatStart(head,12);
    head = insertatStart(head,12);
    head = insertatStart(head,12);
    insertatEnd(head,1);
    insertatMiddle(head,6,3);
    insertatMiddle(head,6,7);
    printlist(head);
    deletelist(head);
    return 0;
}