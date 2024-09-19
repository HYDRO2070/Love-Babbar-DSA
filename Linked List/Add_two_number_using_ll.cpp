// we have been given two lined list which represent number and we have to add them and return a lined list.


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

Node* Reverse(Node *h){
    Node *c = h;
    Node *p = NULL;
    Node *n = NULL;
    while(c != NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}

Node* twosum(Node *h1,Node *h2){
    if(h1 == NULL && h2 == NULL) return NULL;
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;

    h1 = Reverse(h1);
    h2 = Reverse(h2);
    Node *ans = new Node(-1);
    int car = 0;
    while(h1 != NULL && h2 != NULL){
        int v = h1->val + h2->val + car;
        insertatEnd(ans,v%10);
        car = v/10;
        h1 = h1->next;
        h2 = h2->next;
    }
    while(h1 != NULL){
        int v = h1->val + car;
        insertatEnd(ans,v%10);
        car = v/10;
        h1 = h1->next;
    }
    while(h2 != NULL){
        int v = h2->val + car;
        insertatEnd(ans,v%10);
        car = v/10;
        h2 = h2->next;
    }
    if(car != 0){
        insertatEnd(ans,car);
    }
    return Reverse(ans->next);
}

int main(){
    Node *h1 = new Node(1);
    insertatEnd(h1,5);
    Node *h2 = new Node(9);
    insertatEnd(h2,9);
    printlist(h1);
    printlist(h2);
    printlist(twosum(h1,h2));

    deletelist(h1);
    deletelist(h2);
    return 0;
}