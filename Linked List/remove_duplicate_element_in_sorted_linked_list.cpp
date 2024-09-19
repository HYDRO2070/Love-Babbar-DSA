// we have been Given A Sorted Linked List and We have to remove it. and return a unique Linked List.


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


void insertatEnd(Node *head,int val){
    Node *temp = new Node(val);
    while(head->next != NULL){
        head = head->next;
    }
    head->next = temp;

}

void deletelist(Node *head){
    while (head != NULL){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
}

void RemoveDuplicate(Node *head){
    if(head == NULL || head->next == NULL) return;
    Node *n = head->next;
    while(n != NULL){
        if(head->val == n->val){
            Node *temp = n;
            n= n->next;
            head->next = n;
            temp->next = NULL;
            delete temp;
            continue;
        }
        n = n->next;
        head= head->next;
    }
}

int main(){
    Node *head = new Node(1);
    // insertatEnd(head,1);
    // insertatEnd(head,2);
    // insertatEnd(head,2);
    // insertatEnd(head,3);
    // insertatEnd(head,3);
    // insertatEnd(head,3);
    // insertatEnd(head,5);
    printlist(head);
    RemoveDuplicate(head);
    printlist(head);
    deletelist(head);
    return 0;
}