#include<bits/stdc++.h>
using namespace std;

// Brute force Menthod below :-
// int area(vector<int> &r){
//     int ans = 0;
//     for(int i = 0;i < r.size();i++){
//         int cnt = 1;
//         int j = i;
//         while(--j >= 0){
//             if(r[j] >= r[i]) cnt++;
//             else break;
//         }
//         j = i;
//         while(++j < r.size()){
//             if(r[j] >= r[i]) cnt++;
//             else break;
//         }
//         cout<<r[i]*cnt<<endl;
//         ans = max(ans,(r[i]*cnt));
//     }
//     return ans;
// }

// optimize method :-

void print(vector<int> arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverse(vector<int> &ans){
    for(int i = 0;i < ans.size()/2;i++){
        swap(ans[i],ans[ans.size()-1-i]);
    }
}

vector<int> next(vector<int> arr){
    stack<int> s;
    vector<int> ans;
    s.push(-1);
    
    int n = arr.size();
    for(int i = n-1;i >= 0;i--){
        while(s.top() != -1 && arr[s.top()] >= arr[i]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(i);
    }
    reverse(ans);
    return ans;
}

vector<int> previous(vector<int> arr){
    stack<int> s;
    vector<int> ans;
    s.push(-1);
    // 1 2 2 1
    int n = arr.size();
    for(int i = 0;i < n;i++){
        while(s.top() != -1 && arr[s.top()] >= arr[i]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(i);
    }
    return ans;
}


int area(vector<int> r){
    int n = r.size();
    int ans = 0;
    vector<int> pre(n);
    vector<int> nxt(n);
    pre = previous(r);
    nxt = next(r);
    print(pre);
    print(nxt);
    for(int i = 0;i < r.size();i++){
        if(nxt[i] == -1) nxt[i] = n;
        int temp = nxt[i] - pre[i] - 1;
        cout<<r[i]*temp<<" "<<temp<<endl;
        if(temp != -1){
            ans = max(ans,r[i]*temp);
        }
    }
    return ans;
}


int main(){
    vector<int> r;
    r.push_back(1);
    r.push_back(2);
    // r.push_back(2);
    // r.push_back(1);
    r.push_back(5);
    r.push_back(6);
    r.push_back(2);
    r.push_back(3);
    print(r);
    cout<<area(r);
    return 0;
}