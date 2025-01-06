// in this question we have been given 2D matrix and we have to return the maximal rectangle with largest area. L*B.


#include<bits/stdc++.h>
using namespace std;

// void reverse(vector<int> &ans){
//     for(int i = 0;i < ans.size()/2;i++){
//         swap(ans[i],ans[ans.size()-1-i]);
//     }
// }

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
    reverse(ans.begin(),ans.end());
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
    for(int i = 0;i < r.size();i++){
        if(nxt[i] == -1) nxt[i] = n;
        int temp = nxt[i] - pre[i] - 1;
        // cout<<r[i]*temp<<" "<<temp<<endl;
        if(temp != -1){
            ans = max(ans,r[i]*temp);
        }
    }
    return ans;
}

int find(vector<vector<int>> &arr){
    int n = arr[0].size();
    int m = arr.size();
    int ans = 0;
    for(int i = 0;i <n;i++){
        int temp = 0;
        for(int j = 0;j <m;j++){
            if(arr[j][i] == 0){
                temp = 0;

            }
            else{
                temp += arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
    
    for(auto a : arr){
        ans = max(ans,area(a));
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {
        {1,0,1,1,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,1,1,0},
    };
    cout<<find(arr)<<endl;
    return 0;
}