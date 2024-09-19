// In this we have to reverse a evry k group in linked list which is given in the question.

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

Node* reversekgroup(Node *head,int k){
    if(head == NULL){
        return NULL;
    }
    Node *curr = head;
    Node *pre = NULL;
    Node *nex = NULL;
    int cnt = 0;
    while(curr != NULL && cnt < k){
        nex = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nex;
        cnt++;
    }
    // cout<<head->val<<endl;
    if(nex != NULL){
        head->next = reversekgroup(nex,k);
    }
    return pre;
}

int main(){
    Node *head = new Node(5);
    insertatEnd(head,1);
    insertatEnd(head,2);
    insertatEnd(head,3);
    insertatEnd(head,4);
    printlist(head);
    printlist(reversekgroup(head,3));
    deletelist(head);
    return 0;
}