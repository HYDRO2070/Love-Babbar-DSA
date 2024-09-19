#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
    char val;
    trienode *arr[26];
    int count;
    bool isterminal;
    trienode(char val){
        this->val = val;
        this->count = 0;
        for(int i =0;i < 26;i++){
            arr[i] = NULL;
        }
        isterminal = false;
    }

    void insertword(trienode *root,string s){
        if(!s.size()){
            root->isterminal = true;
            return;
        }
        if(root->arr[s[0] - 'a'] == NULL){
            root->count++;
           root->arr[s[0] - 'a'] = new trienode(s[0]);
        }
        insertword(root->arr[s[0] - 'a'],s.substr(1));
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
};

void addelement(trienode *root,vector<string> &temp,string pre){
    // cout<<"jejjeje"<<endl;
    if(root->isterminal){
        temp.push_back(pre);
        if(root->count == 0) return;
    }
    for(int i = 0;i < 26;i++){
        if(root->arr[i]){
            addelement(root->arr[i],temp,pre+root->arr[i]->val);
        }
    }
    return;
}

// void sol(trienode *root,vector<string> &temp,string &s){
//     cout<<s<<endl;
//     root = root->arr[s[0] - 'a'];
//     for(int i = 0;i < s.size();i++){
//         if(root->val == s[i]){
//             if(i+1 < s.size()){
//                 if(root->arr[s[i+1] - 'a'] != NULL){
//                     root = root->arr[s[i+1] - 'a'];
//                 }
//                 else{
//     // cout<<"start"<<endl;
//                     return;
//                 }
//             }
//         }
//         else{
//             return;
//         }
//     }
//     addelement(root,temp,s);
// }


vector<vector<string> > solve(vector<string> &arr,string s){
    // cout<<"start"<<endl;
    vector<vector<string> > ans;
    trienode *root = new trienode('\0');
    for(int i = 0;i < arr.size();i++){
        root->insertword(root,arr[i]);
    }
    // cout<<"start"<<endl;
    string te = "";

    // trienode *pre = 
    for(int i = 0;i < s.size();i++){
        vector<string> temp;
        te += s[i];
         if(root->arr[s[i] - 'a'] != NULL){
            root = root->arr[s[i] - 'a'];
            addelement(root,temp,te);
         }
        // sol(root,temp,te);
        // cout<<temp.size()<<endl;
        ans.push_back(temp);
    }
    return ans;
}


void print(vector<vector<string> > s){
    // cout<<s.size();
    // cout<<s[0].size();
    for(auto i : s){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    vector<string> arr;
    arr.push_back("cod");
    arr.push_back("coding");
    arr.push_back("coder");
    arr.push_back("codelove");
    arr.push_back("haleluiya");
    arr.push_back("pagal");
    print(solve(arr,"coding"));
    return 0;
}