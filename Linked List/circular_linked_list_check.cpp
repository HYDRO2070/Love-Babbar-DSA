// we have to check if the list is circular or not. return true or false.

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

bool checkCircular(Node *head){
    if(head == NULL || head->next == head){
        return true;
    }
    if(head->next == NULL){
        return false;
    }
    Node *temp = head;
    head= head->next;
    while(head != NULL){
        if(head == temp) return true;
        head = head->next;
    }
    return false;
}

int main(){
    
    Node *head = new Node(1);
    head->next = head;
    // InsertatEnd(head,8);
    // InsertatEnd(head,7);
    // InsertatEnd(head,6);
    // InsertatEnd(head,9);
    printlist(head);
    cout<<checkCircular(head);
    deletelist(head);
    return 0;
}