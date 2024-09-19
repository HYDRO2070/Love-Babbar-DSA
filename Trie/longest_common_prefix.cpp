

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


int solve(trienode *root){
    int ans = 0;
    int temp = 0;
    int po = -1;
    for(int i = 0;i < 26;i++){
        if(root->arr[i] != NULL){
            po = i;
            temp++;
        }
    }
    if(temp == 1){
        ans++;
        return ans + solve(root->arr[po]);
    }
    return ans;
}


string LCP(vector<string> &arr){
    // string ans = "";
    // for(int i = 0;i < arr[0].size();i++){
    //     bool temp = false;
    //     for(int j = 1;j < arr.size();j++){
    //         if(arr[j].size() > i && arr[i][i] == arr[j][i]){
    //             temp = true;
    //             // ans += arr[i][i];
    //         }
    //         else return ans;
    //     }
    //     if(temp == true) ans += arr[i][i];
    // }
    // return ans;

    trie *root = new trie();
    string ans = "";
    for(int i = 0;i < arr.size();i++){
        root->insert(arr[i]);
    }
    int len = solve(root->root);
    for(int i = 0;i < len;i++){
        ans += arr[0][i];
    }
    return ans;
}


int main(){
    vector<string> arr;
    arr.push_back("coding");
    arr.push_back("coder");
    arr.push_back("code");
    arr.push_back("codo");
    cout<<LCP(arr)<<endl;
    
    return 0;
}