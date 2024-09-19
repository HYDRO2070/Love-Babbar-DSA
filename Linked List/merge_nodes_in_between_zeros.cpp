// in this question we have been given a list and 0 seperated number we have to merge the number between zero and return a new list of merge number.


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

Node* merge_node(Node *head){
    Node *ans = new Node(-1);
    Node *ptr = ans;
    int temp = 0;
    head = head->next;
    while(head != NULL){
        if(head->val == 0){
            // insertatEnd(ans,temp);
            Node *te = new Node(temp);
            ans->next = te;
            ans = ans->next;
            ans->next = NULL;
            temp = 0;
        }
        temp += head->val;
        head = head->next;
    }
    return ptr->next;
}

int main(){
    Node *h1 = new Node(0);
    insertatEnd(h1,1);
    insertatEnd(h1,0);
    insertatEnd(h1,3);
    insertatEnd(h1,0);
    insertatEnd(h1,2);
    insertatEnd(h1,2);
    insertatEnd(h1,0);
    printlist(h1);
    printlist(merge_node(h1));
    deletelist(h1);
    return 0;
}