#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *left,*right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

Node* pushnode(Node *root,int val){
    // cout<<"Hello"<<endl;
    if(root == NULL){
        return new Node(val);
    }
    if(root->val > val){
        root->left = pushnode(root->left,val);
    }
    else{
        root->right = pushnode(root->right,val);
    }
    return root;
}

Node* create_bst(int *arr,int n){
    Node *root = NULL;
    for(int i = 0;i < n;i++){
        root = pushnode(root,arr[i]);
    }
    return root;
}

void inorder(Node *root){
    if(root == NULL) return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


void convertto_dll(Node *root,Node *&head){
    // cout<<"H"<<endl;
    if(root == NULL) return;
    convertto_dll(root->right,head);
    root->right = head;
    if(head != NULL) head->left = root;
    head = root;
    convertto_dll(root->left,head);
}

Node* merge_linked_list(Node *r1,Node *r2){
    Node *head = NULL;
    Node *tail = NULL;

    while(r1 != NULL && r2 != NULL){
        // cout<<r1->val<<" "<<r2->val<<endl;
        if(r1->val < r2->val){
            if(head == NULL){
                head = r1;
                tail = r1;
                r1 = r1->right;
            }
            else{
                tail->right = r1;
                r1->left = tail;
                tail = r1;
                r1 = r1->right;
            }
        }
        else{
            if(head == NULL){
                head = r2;
                tail = r2;
                r2 = r2->right;
            }
            else{
                tail->right = r2;
                r2->left = tail;
                tail = r2;
                r2 = r2->right;
            }

        }
    }
    while(r1 != NULL){
        // cout<<r1->val<<endl;
        tail->right = r1;
        r1->left = tail;
        tail = r1;
        r1 = r1->left;
    }
    while(r2 != NULL){
        // cout<<r2->val<<endl;
        tail->right = r2;
        r2->left = tail;
        tail = r2;
        r2 = r2->right;
    }
    return head;
}

Node* ll_to_bst(Node *&root,int n){
    if(n <= 0 || root == NULL) return NULL;

    Node *left = ll_to_bst(root,n/2);
    Node *head = root;
    cout<<head->val<<" "<<n<<endl;
    head->left = left;
    root = root->right;
    if(n&1) n++;
    head->right = ll_to_bst(root,n/2 - 1);
    return head;
}

int find(Node *root){
    // cout<<"g"<<endl;
    int i = 0;
    while(root != NULL){
        i++;
        // cout<<root->val<<" ";
        root = root->right;
    }
    return i;
}

Node* solve(Node *root,Node *head){
    Node *h1 = NULL;
    Node *h2 = NULL;
    convertto_dll(root,h1);
    convertto_dll(head,h2);
    h1->left = NULL;
    h2->left = NULL;
    Node *ans = merge_linked_list(h1,h2);
    int count = find(ans);
    cout<<endl<<count<<endl;
    return ll_to_bst(ans,count);

}



int main(){
//                 10
//             8        21
//           7   9          27
//       5
//    4
// 3

// 3 4 5 7 8 9 10 21 27 
    int arr[9] = {10,8,21,7,27,5,4,3,9};
    Node *root = create_bst(arr,9);
    inorder(root);
    cout<<endl;
    int arr1[9] = {14,87,90,45,12,54,17,22,21};
    Node *head = create_bst(arr1,9);
    inorder(head);
    cout<<endl;
    Node *ans = solve(root,head);
    cout<<"Hello"<<endl;
    inorder(ans);
    cout<<endl;
    return 0;
}