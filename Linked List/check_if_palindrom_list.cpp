// we have to check if the given list is palindrom.


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

bool ispalindrom(Node *head){
    if(head == NULL) return false;
    string ans = "";
    while(head != NULL){
        ans += '0'+head->val;
        head = head->next;
    }
    string temp = ans;
    reverse(ans.begin(),ans.end());
    return ans == temp;

}

int main(){
    Node *head = new Node(1);
    insertatEnd(head,2);
    insertatEnd(head,4);
    insertatEnd(head,9);
    insertatEnd(head,4);
    // insertatEnd(head,2);
    insertatEnd(head,1);
    // insertatEnd(head2,8);
    printlist(head);
    cout<<ispalindrom(head);

    deletelist(head);
    return 0;
}