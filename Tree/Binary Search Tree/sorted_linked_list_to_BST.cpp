

// Node* ll_to_bst(Node *&root,int n){
//     if(n <= 0 || root == NULL) return NULL;

//     Node *left = ll_to_bst(root,n/2);
//     Node *head = root;
//     root->left = left;
//     root->right = ll_to_bst(root,n/2 - 1);
// }