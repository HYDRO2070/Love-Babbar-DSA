// there are multiple question in this problem like below
// 1. We have to detect if the list have a cycle or not.
// 2. if it have cycle than from which node it start.
// 3. if it have cycle than from which node it end.
// 4. remove the cycle by placing NULL to the end of the cycle.


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

void InsertatEnd(Node *head,int val){
    Node *n = new Node(val);
    if(head->next == NULL){

        // cout<<"jejej"<<endl;
        head->next = n;
        n->next = head;
        return;
    }
    Node *temp = head;

    head = head->next;
    while(head->next != temp && head != NULL){
        head = head->next;
    }
    head->next = n;
    n->next = temp;
}

bool checkCircular(Node *head){
    if(head == NULL) return true;
    map<Node*,bool> visited;
    while(head != NULL){
        if(visited[head] == true){
            return true;
        }
        visited[head] = true;
        head = head->next;
    }
    return false;
}
Node* floydelectloop(Node *head){
    if(head == NULL) return NULL;
    Node *t = head;
    Node *temp = head;
    while(temp != NULL && head != NULL){
        // cout<<"helleo"<<endl;
        temp = temp->next;
        if(temp != NULL)
        temp = temp->next;
        head = head->next;
        if(temp == head) break;
    }
    if(temp != NULL && head != NULL){
        head = t;
        while(head != temp){
            head = head->next;
            temp = temp->next;
        }
        return head;
    }
    return NULL;
}

void printlist1(Node *head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void removeloop(Node *head){
    if(head == NULL) return;
    Node *s = floydelectloop(head);
    head = s;
    while(head->next != s){
        head = head->next;
    }
    head->next = NULL;
}

int main(){
    
    Node *head = new Node(1);
    head->next = head;
    InsertatEnd(head,8);
    InsertatEnd(head,7);
    InsertatEnd(head,6);
    InsertatEnd(head,9);
    printlist(head);
    head->next->next->next->next->next = head->next->next;
    // cout<<floydelectloop(head);
    removeloop(head);
    printlist1(head);
    deletelist(head);
    return 0;
}