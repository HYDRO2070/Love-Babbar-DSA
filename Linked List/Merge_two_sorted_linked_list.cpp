// we have been given two sorted list and we have to merge them create a new sorted list. single only.


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

Node* mergelist(Node *h1,Node *h2){
    if((h1 == NULL && h2 == NULL)) return NULL;
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    Node *ans = h1;
    Node *pre = h1;
    h1 = h1->next;
    while(h1 != NULL && h2 != NULL){
        // cout<<pre->val<<" "<<h1->val<<endl;
        if(pre->val <= h2->val && h1->val >= h2->val){
            Node *temp = h2;
            h2= h2->next;
            pre->next = temp;
            temp->next = h1;
            pre = temp;
            continue;
        }
        pre= pre->next;
        h1=h1->next;
    }
    if(h1 == NULL && h2 != NULL){
        pre->next = h2;
    }
    return ans;
}

int main(){
    Node *head1 = new Node(1);
    // insertatEnd(head1,2);
    // insertatEnd(head1,4);
    // insertatEnd(head1,9);
    Node *head2 = new Node(3);
    // insertatEnd(head2,5);
    // insertatEnd(head2,6);
    // insertatEnd(head2,7);
    // insertatEnd(head2,8);
    printlist(head1);
    printlist(head2);
    
    printlist(mergelist(head1,head2));

    deletelist(head1);
    deletelist(head2);
    return 0;
}