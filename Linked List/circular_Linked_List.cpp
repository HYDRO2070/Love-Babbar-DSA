// IN this last pointer store head address.

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

Node* InsertAtHead(Node *head,int val){
    if(head == NULL){
        head = new Node(val);
        head->next = head;
        return head;
    }
    Node *temp = new Node(val);
    Node *t1 = head->next;
    Node *t = head;
    temp->next = head;
    head = temp;
    if(t1 == NULL){
        t->next = temp;
    }
    while(t1->next != t){
        t1 = t1->next;
    }
    t1->next = temp;
    return head;
}

void InsertatEnd(Node *head,int val){
    Node *temp = head;

    head = head->next;
    while(head->next != temp && head != NULL){
        head = head->next;
    }
    Node *n = new Node(val);
    if(head == NULL){
        temp->next = n;
        n->next = temp;
    }
    head->next = n;
    n->next = temp;
}

Node* InsertByValue(Node *head,int d,int val){
    Node *t = head;
    Node *temp = new Node(val);
    if(d == t->val){
        temp->next = head->next;
        head->next = temp;
    }
    head = head->next;
    while(head->val != d && head->val != t->val){
        head = head->next;
    }
    if(head == t){
        return t;
    }
    temp->next = head->next;
    head->next = temp;
    return t;
}

Node* DeleteByValue(Node *head,int val){

    Node *temp = head;
    if(head->val == val){
        while(head->next != temp){
            head = head->next;
        }
        head->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head->next;
    }
    Node *t = head;
    head = head->next;
    while(head->val != val && head != temp){
        t = head;
        head = head->next;
    }
    t->next = head->next;
    head->next = NULL;
    delete head;
    return temp;

}

int main(){
    
    Node *head = NULL;
    head = InsertAtHead(head,1);
    head = InsertAtHead(head,2);
    head = InsertAtHead(head,3);
    head = InsertAtHead(head,4);
    InsertatEnd(head,8);
    InsertatEnd(head,7);
    InsertatEnd(head,6);
    head = InsertByValue(head,1,9);
    printlist(head);
    head = DeleteByValue(head,4);
    printlist(head);
    deletelist(head);
    return 0;
}