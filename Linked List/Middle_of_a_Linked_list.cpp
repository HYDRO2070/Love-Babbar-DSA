// return middle element of the list

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

Node* middleelement(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    if(head->next->next == NULL){
        return head->next;
    }
    Node *pre = head;
    while(head->next != NULL && head->next->next != NULL){
        // cout<<"hii"<<endl;
        head = head->next->next;
        pre = pre->next;
    }
    if(head->next != NULL)
    pre = pre->next;
    return pre;
}

int main(){
    Node *head = new Node(5);
    insertatEnd(head,1);
    insertatEnd(head,2);
    insertatEnd(head,3);
    // insertatEnd(head,4);
    printlist(head);
    cout<<middleelement(head)->val;
    deletelist(head);
    return 0;
}