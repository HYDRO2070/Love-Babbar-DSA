// applying merge_sort in linked list


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

// Node* Reverse(Node *h){
//     Node *c = h;
//     Node *p = NULL;
//     Node *n = NULL;
//     while(c != NULL){
//         n = c->next;
//         c->next = p;
//         p = c;
//         c = n;
//     }
//     return p;
// }

Node* mergelist(Node *h1,Node *h2){
    if((h1 == NULL && h2 == NULL)) return NULL;
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    Node *ans = new Node(0);
    while(h1 != NULL && h2 != NULL){
        if(h1->val <= h2->val){
            insertatEnd(ans,h1->val);
            h1 = h1->next;
        }
        else{
            insertatEnd(ans,h2->val);            
            h2 = h2->next;
        }
    }
    while(h1!=NULL){
            insertatEnd(ans,h1->val);
            h1 = h1->next;
    }
    while(h2!=NULL){
            insertatEnd(ans,h2->val);
            h2 = h2->next;
    }
    // printlist(ans);
    return ans->next;

    
}

Node* middle(Node *head){
    // cout<<"hello1111111111111"<<endl;
    if(head->next == NULL) return head;
    Node *fast = head->next;
    while(fast !=NULL && fast->next !=NULL){
        head = head->next;
        fast = fast->next->next;
    }
    return head;
}

Node* merge_sort(Node *head){
    // cout<<"hello"<<endl;
    if(head == NULL || head->next == NULL) return head;
    Node *mid = middle(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    left = merge_sort(left);
    right = merge_sort(right);
    Node *ans = mergelist(left,right);
    // printlist(ans);
    return ans;
}


int main(){
    // 2,4,6,1,87,5,343,66,-1
    Node *h1 = new Node(2);
    insertatEnd(h1,4);
    insertatEnd(h1,6);
    insertatEnd(h1,1);
    insertatEnd(h1,87);
    insertatEnd(h1,5);
    insertatEnd(h1,343);
    insertatEnd(h1,66);
    insertatEnd(h1,-1);
    printlist(h1);
    printlist(merge_sort(h1));
    deletelist(h1);
    return 0;
}