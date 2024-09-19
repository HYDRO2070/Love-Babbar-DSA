// we habe been given a list and we have to reverse it.

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

// void relist(Node* &head,Node* &curr,Node* &pre){
//     if(curr == NULL){
//         head = pre;
//         return;
//     }
//     // nex = curr->next;
//     // curr->next = pre;
//     // pre = curr;
//     // curr = nex;     
//     relist(head,curr->next,curr);
//     curr->next = pre;
// }

Node* ReverseList(Node *head){
    // Node *curr = head;
    // Node *pre = NULL;
    // // Node *nex = NULL;

    // // while(curr != NULL){
    // //     nex = curr->next;
    // //     curr->next = pre;
    // //     pre = curr;
    // //     curr = nex;        
    // // }
    // relist(head,curr,pre);
    // return head;

    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *temp = ReverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

int main(){
    Node *head = new Node(5);
    insertatEnd(head,1);
    insertatEnd(head,2);
    insertatEnd(head,3);
    insertatEnd(head,4);
    printlist(head);
    printlist(ReverseList(head));
    deletelist(head);
    return 0;
}