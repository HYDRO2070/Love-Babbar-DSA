// we have been given linked list with three field data,next pointer and a random node pointer and we have to clone it


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *next;
    Node *ran;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->ran = NULL;
    }
};

void printlist(Node *head){
    while(head != NULL){
        cout<<head->val<<" -> "<<head->ran->val<<endl;
        head = head->next;
    }
    cout<<endl;
}


void insertatEnd(Node *head,int val){
    Node *temp = new Node(val);
    // temp->ran = temp;
    if(head == NULL){
        head = temp;
        return;
    }
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
        temp->ran = NULL;
        delete temp;
    }
    
}


Node* clone(Node *head){
    if(head == NULL) return NULL;
    Node *temp = new Node(head->val);
    Node *t = head->next;
    while(t != NULL){
        insertatEnd(temp,t->val);
        t = t->next;
    }

    //using mapping  

    // map<Node*,Node*> mapping;
    // t = head;
    // Node *t2 = temp;
    // while(t != NULL){
    //     mapping[t] = t2;
    //     t= t->next;
    //     t2 = t2->next;
    // }
    // t = head;
    // t2 = temp;
    // while(t2 != NULL){
    //     t2->ran = mapping[t->ran];
    //     t2 = t2->next;
    //     t = t->next;
    // }

    // without using mapping
    t = head;
    Node *t2 = temp;
    Node *i = NULL;
    while(t != NULL && t2 != NULL){
        i = t2->next;
        t2->next = t->next;
        t->next = t2;
        t = t2->next;
        t2 = i;
    }
    t = head;
    t2 = temp;
    while(t != NULL){
        t->next->ran = t->ran->next;
        t = t->next->next;
    }

    t = head;
    t2 = temp;
    i = NULL;
    while(t != NULL && t2 != NULL){
        i = t2->next;
        if(i == NULL) t2->next = NULL;
        else t2->next = i->next;
        t->next = i;
       
        t = i; t2 = t2->next;
    }

    return temp;


}

int main(){
    Node *h = new Node(1);
    insertatEnd(h,2);
    insertatEnd(h,3);
    insertatEnd(h,4);
    insertatEnd(h,5);

    h->ran = h->next->next;
    h->next->ran = h;
    h->next->next->ran = h->next->next->next->next;
    h->next->next->next->ran = h->next->next;
    h->next->next->next->next->ran = h->next;
    printlist(h);
    printlist(clone(h));
    deletelist(h);
    return 0;
}