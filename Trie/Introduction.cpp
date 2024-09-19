// trie is a data structure which use char or string to perform any operation
// complexity O(l) where lis length of the word.

#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
    char val;
    trienode *arr[26];
    bool isterminal;
    trienode(char val){
        this->val = val;
        for(int i =0;i < 26;i++){
            arr[i] = NULL;
        }
        isterminal = false;
    }

    void insertion(trienode *root,string s){
        // hello
        if(!s.size()) return;
        int i = 0;
        while(i < s.size()){
            if(root->arr[s[i] - 'a'] == NULL){
                root->arr[s[i] - 'a'] = new trienode(s[i]);
            }
            root = root->arr[s[i] - 'a'];
            i++;
            // cout<<root->val<<endl;
        }
        root->isterminal = true;
        // cout<<root->val<<endl;
    }

    bool search(trienode *root,string s){
        if(!s.size()) return false;
        int i = 0;
        while(i < s.size()){
        // cout<<root->arr[s[i] - 'a']->val<<endl;
            if(root->arr[s[i] - 'a'] == NULL){
                return false;
            }
            root = root->arr[s[i] - 'a'];
            i++;
        }
        if(root->isterminal == true) return true;
        return false;
    }

};

class trie{
    public:
    trienode *root;

    trie(){
        root = new trienode('\0');
    }
    void insertword(trienode *root,string s){
        if(!s.size()){
            root->isterminal = true;
            return;
        }
        if(root->arr[s[0] - 'a'] == NULL){
           root->arr[s[0] - 'a'] = new trienode(s[0]);
        }
        insertword(root->arr[s[0] - 'a'],s.substr(1));
    }
    void insert(string s){
        insertword(root,s);
    }
    
    bool searchword(trienode *root,string s){
        if(s.size() <= 0){
            return root->isterminal;
        }
        if(root->arr[s[0] - 'a'] == NULL){
            return false;
        }
        return searchword(root->arr[s[0] - 'a'],s.substr(1));
    }
    
    bool search(string s){
        return searchword(root,s);
    }

    bool deleword(trienode *root,string s){
        if(s.size() <= 0){
            if(root->isterminal){
                root->isterminal = false;
                return true;
            }
            return root->isterminal;
        }
        if(root->arr[s[0] - 'a'] == NULL){
            return false;
        }
        return deleword(root->arr[s[0] - 'a'],s.substr(1));
    }


    bool dele(string s){
        return deleword(root,s);
    }
};


int main(){
    // trienode *root = new trienode(' ');
    // root->insertion(root,"hello");
    // cout<<root->search(root,"hello");
    trie *root = new trie();
    root->insert("hello");
    cout<<root->search("hello")<<endl;
    cout<<root->dele("hello");
    cout<<root->search("hello")<<endl;
    
    return 0;
}