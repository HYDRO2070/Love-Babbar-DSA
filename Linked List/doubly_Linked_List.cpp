// the Linked List which have two pointer pre and next than it is know as doubly Linked List.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *pre;
    Node *next;
    Node(int val){
        this->val = val;
        this->pre = NULL;
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
void printreverse(Node *head){
    while(head->next != NULL){
        head = head->next;
    }

    while(head != NULL){
        cout<<head->val<<" ";
        head = head->pre;
    }
    cout<<endl;
}

int getlen(Node *head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node* InsertatHead(Node *head,int val){
    Node *temp = new Node(val);
    temp->next = head;
    head->pre = temp;
    head = temp;
    return head;
}

void InsertatEnd(Node *head,int val){
    while(head->next != NULL){
        head = head->next;
    }
    Node *temp = new Node(val);
    head->next = temp;
    temp->pre = head;
}

Node* insertatMiddle(Node *head,int val,int p){
    if(p == 1){
        head = InsertatHead(head,val);
        return head;
    }
    Node *temp = head;
    int cnt = 2;
    while(cnt < p && head->next != NULL){
        head = head->next;
        cnt++;
    }
    if(head->next == NULL){
        InsertatEnd(head,val);
    }
    else{
        Node *tem = new Node(val);
        tem->next = head->next;
        head->next->pre = tem;
        head->next = tem;
        tem->pre = head;
    }

    return temp;
}

Node* deleteNode(Node *head,int p){
    if(p == 1){
        Node *temp = head;
        head = head->next;
        head->pre = NULL;
        temp->next = NULL;
        delete temp;
        return head;
    }
    Node *temp = head;
    int cnt = 1;
    while(cnt+1 < p && head->next != NULL){
        head = head->next;
        cnt++;
    }
    if(head->next->next == NULL){
        cout<<"Hello"<<endl;
        Node *tem = head->next;
        head->next = NULL;
        tem->next = NULL;
        tem->pre = NULL;
    delete tem;
    }
    else{
        Node *tem = head->next;
        head->next = tem->next;
        tem->next->pre = head;
        tem->next = NULL;
        tem->pre = NULL;
    delete tem;
    }
    return temp;
}

void deletelist(Node *head){
    while (head != NULL){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        temp->pre = NULL;
        free(temp);
    }
    
}

int main(){
    Node *head = new Node(1);
    head = InsertatHead(head,2); 
    InsertatEnd(head,3); 
    InsertatEnd(head,4); 
    InsertatEnd(head,5); 
    insertatMiddle(head,9,6);
    // printf("%d\n",getlen(head));
    head = deleteNode(head,6);
    printlist(head);
    printreverse(head);
    deletelist(head);
    return 0;
}