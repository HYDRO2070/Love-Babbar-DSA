// we have been Given A UNSorted Linked List and We have to remove Duplicate. and return a unique Linked List.


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
    // Node *n = head->next;
    int mask = 0;
    mask |= 1 << (head->val);
    while(head->next != NULL){

        int temp = 1 << (head->next->val);
        if(mask & temp) {
            // cout<<"head"<<head->val<<endl;
            Node *temp = head->next;
            head->next = temp->next;
            temp->next = NULL;
            delete temp;
            continue;
        }
        else mask |= temp;

        // if(head->val == n->val){
        //     Node *temp = n;
        //     n= n->next;
        //     head->next = n;
        //     temp->next = NULL;
        //     delete temp;
        //     continue;
        // }
        // n = n->next;
        head= head->next;
    }
}

int main(){
    Node *head = new Node(1);
    insertatEnd(head,4);
    insertatEnd(head,8);
    insertatEnd(head,1);
    insertatEnd(head,9);
    insertatEnd(head,9);
    insertatEnd(head,8);
    insertatEnd(head,4);
    printlist(head);
    RemoveDuplicate(head);
    printlist(head);
    deletelist(head);
    return 0;
}