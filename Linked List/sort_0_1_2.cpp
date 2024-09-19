// we have tp sort 0 1 2. that's all we have to do.

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

// void sort(Node *head){
//     int c_0 = 0;
//     int c_1 = 0;
//     int c_2 = 0;
//     Node *temp = head;
//     while(temp != NULL){
//         if(temp->val == 0) c_0++;
//         else if(temp->val == 1) c_1++;
//         else c_2++;
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp != NULL){
//         if(c_0 != 0){ temp->val = 0; c_0--;}
//         else if(c_1 != 0) {temp->val = 1; c_1--;}
//         else temp->val = 2;
//         temp = temp->next;
//     }
// }


void insertattail(Node *&tail,Node *c){
    // cout<<tail->val<<" "<<c->val<<endl;
    tail->next = c;
    tail = c;
    // tail->next = NULL;
}

Node* sort2(Node *head){
    Node *zero = new Node(-1);
    Node *zerotail = zero;
    Node *one = new Node(-1);
    Node *onetail = one;
    Node *two = new Node(-1);
    Node *twotail = two;
    Node *c = head;
    while(c != NULL){
        if(c->val == 0) insertattail(zerotail,c);
        else if(c->val == 1) insertattail(onetail,c);
        else insertattail(twotail,c);
        c= c->next;
    }
    // printlist(zero);
    // printlist(one);
    // printlist(two);
    // printlist(two);
    // if(zero->next != NULL)
    head = zero->next;
    // if(one->next != NULL)
    zerotail->next = one->next;
    onetail->next = two->next;
    twotail->next = NULL;

    zero->next = NULL;
    one->next = NULL;
    two->next = NULL;
    delete zero;
    delete one;
    delete two;

    return head;
}

int main(){
    Node *head = new Node(0);
    insertatEnd(head,1);
    insertatEnd(head,2);
    insertatEnd(head,0);
    insertatEnd(head,0);
    insertatEnd(head,1);
    insertatEnd(head,2);
    insertatEnd(head,1);
    printlist(head);
    
    printlist(sort2(head));
    deletelist(head);
    return 0;
}