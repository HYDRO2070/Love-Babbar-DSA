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
    // ~Node(){
    //     delete this->next;
    // }
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

Node* deleteNode(Node *head,int p){
    if(p == 1){
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    int cnt = 1;
    while(cnt+1 < p && head->next != NULL){
        head = head->next;
        cnt++;
    }
    Node *tem = head->next;
    head->next = head->next->next;
    delete tem;
    return temp;
}

void deletelist(Node *head){
    while (head != NULL){
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    
}

int main(){
    
    Node *head = new Node(1);
    head = insertatStart(head,-1);
    // head = insertatStart(head,-2);
    // insertatMiddle(head,2,4);
    // insertatMiddle(head,3,5);
    // insertatEnd(head,4);
    head = deleteNode(head,2);
    printlist(head);
    deletelist(head);
    printlist(head);

    return 0;
}