// In this question we have been given 2d linked list and we have to make it in singly list and sorted also.

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    Node *child;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->child = NULL;
    }
};

void Print2dlist(Node *head){
    if(head == NULL) return;
    while(head != NULL){
        cout<<head->val<<" ";
        while(head->child != NULL){
            cout<<head->child->val<<" ";
            head->child = head->child->child;
        }
        cout<<endl;
        head = head->next;
    }
}
void dele(Node *head){
    if(head == NULL) return;
    Node *temp = NULL;
    // Node *temp1 = NULL;
    while(head != NULL){
        // cout<<head->val<<" ";
        while(head->child != NULL){
            temp = head->child;
            // cout<<head->child->val<<" ";
            head->child = head->child->child;
            temp->next = NULL;
            free(temp);
        }
        temp = head;
        // cout<<endl;
        head = head->next;
        temp->next = NULL;
        temp->child = NULL;
        delete temp;
    }
}

void insertatEnd(Node *head,int val){
    if(head == NULL) return;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = new Node(val);
}

Node* merge(Node *h1,Node *h2){
    if((h1 == NULL && h2 == NULL)) return NULL;
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    Node *ans = new Node(0);
    while(h1 != NULL && h2 != NULL){
        if(h1->val <= h2->val){
        cout<<"hello"<<endl;
            insertatEnd(ans,h1->val);
            h1 = h1->child;
            // if(h1 == NULL) cout<<"true"<<endl;
            // cout<<h1->val<<endl;
        }
        else{
            insertatEnd(ans,h2->val);            
            h2 = h2->next;
        }
    }
    while(h1!=NULL){
            insertatEnd(ans,h1->val);
            h1 = h1->child;
    }
    while(h2!=NULL){
            insertatEnd(ans,h2->val);
            h2 = h2->next;
    }
    // printlist(ans);
    // cout<<"kfmkfmrkfm"<<endl;
    // cout<<"------"<<endl;
    // Print2dlist(ans);
    // cout<<"------"<<endl;
    return ans->next;

}

Node* fallten(Node *head){
    if(head == NULL) return NULL;
    // cout<<head->child->val<<endl;
    Node *down = head;
    // cout<<"kfmkfmrkfm"<<endl;
    Node *right = fallten(head->next);
    down->next = NULL;
    // cout<<down->child->val<<endl;
    // Print2dlist(down);
    Node *ans = merge(down,right);
    return ans;
    // Print2dlist(head);
    // return NULL;
}

int main(){
    Node *head = new Node(1);
    head->child = new Node(2);
    head->child->child = new Node(3);
    head->next = new Node(4);    
    head->next->child = new Node(5);    
    head->next->child->child = new Node(6);    
    head->next->next = new Node(7);    
    head->next->next->child = new Node(8);    
    head->next->next->next = new Node(9);    
    head->next->next->next->child = new Node(12);    
    head->next->next->next->next = new Node(20);  
    // Print2dlist(head);
    Print2dlist(fallten(head));
    dele(head);

    return 0;
}