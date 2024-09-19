#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
    int val;
    struct node *next;
} typedef node;

node* createnode(int val){
    node *p = (node*)malloc(sizeof(node));
    p->val = val;
    p->next = NULL;
    return p;
}
void insertlist(node *head,int val){
    if(head == NULL){
        return;
    }
    while (head ->next != NULL){
        head  =  head->next;
    }
    node *temp = createnode(val);
    head->next = temp;  
}
void shower(node *head){
    while (head != NULL){
        cout<<head->val << " ";
        head  =  head->next;
    }
    cout<<endl;
}
node* mergelist(node* head1,node* head2){
    if(head1 == NULL && head2 == NULL){
        return NULL;
    }
    if(head1 == NULL ){
        return head2;
    }
    if(head2 == NULL ){
        return head1;
    }
    node* ans = createnode(0);
    while(head1 != NULL && head2 != NULL){
        if(head1->val > head2->val){
            insertlist(ans,head2->val);
            head2 = head2->next;
        }
        else{
            insertlist(ans,head1->val);
            head1 = head1->next;
        }
    }
    while (head1!=NULL)
    {
        insertlist(ans,head1->val);
        head1 = head1->next;
    }
    while (head2!=NULL)
    {
        insertlist(ans,head2->val);
        head2 = head2->next;
    }
    return ans->next;
}
node* mergeklist(node* arr[],int size){
    if(arr[0] == NULL){
        return NULL;
    }
    int i = 0;
    node* ans = createnode(-1);
    while(i < size){
        ans = mergelist(ans,arr[i]);
        i = i + 1;
    }
    return ans->next;
}
int main(){
    node* arr[3] = {NULL};

    // arr[0] = NULL;
    // insertlist(arr[0],4);
    // insertlist(arr[0],5);
    // arr[1] = NULL;
    // insertlist(arr[1],3);
    // insertlist(arr[1],4);
    // arr[2] = createnode(2);
    // insertlist(arr[2],6);
    // shower(arr[0]);
    // shower(arr[1]);
    // shower(arr[2]);
    node* ans = mergeklist(arr,2);
    shower(ans);
    node *temp;
    while(arr[0] != NULL){
        temp = arr[0];
        arr[0] = arr[0]->next;
        free(temp);
    }
    while(arr[1] != NULL){
        temp = arr[1];
        arr[1] = arr[1]->next;
        free(temp);
    }
    while(ans != NULL){
        temp = ans;
        ans = ans->next;
        free(temp);
    }
    while(arr[2] != NULL){
        temp = arr[2];
        arr[2] = arr[2]->next;
        free(temp);
    }
    free(temp);

    return 0;
}