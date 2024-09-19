#include<bits/stdc++.h>
using namespace std;

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

vector<int> next(int *arr,int n){
    stack<int> s;
    vector<int> ans;
    s.push(-1);
    // 1 2 2 1
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

vector<int> previous(int *arr,int n){
    stack<int> s;
    vector<int> ans;
    s.push(-1);
    
    for(int i = 0;i < n;i++){
        while(s.top() != -1 && arr[s.top()] >= arr[i]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(i);
    }
    return ans;
}


int area(int *r,int n){
    int ans = 0;
    vector<int> pre(n);
    vector<int> nxt(n);
    pre = previous(r,n);
    nxt = next(r,n);
    // print(pre);
    // print(nxt);
    for(int i = 0;i < n;i++){
        if(nxt[i] == -1) nxt[i] = n;
        int temp = nxt[i] - pre[i] - 1;
        // cout<<r[i]*temp<<" "<<temp<<endl;
        if(temp != -1){
            ans = max(ans,r[i]*temp);
        }
    }
    return ans;
}

int compute_Area(int arr[][4],int n){
    int ans = area(arr[0],n);
    for(int i = 1;i < n;i++){
        for(int j = 0;j < n;j++){
            if(arr[i][j] != 0){
                arr[i][j] = arr[i][j] + arr[i-1][j];
            }
            else{
                arr[i][j] = 0;
            }
            // cout<<arr[i][j]<<" ";
        }
        ans = max(ans,area(arr[i],n));
        // cout<<endl;
        // cout<<ans<<endl;
    }
    return ans;
}

int main(){
    
    int arr[4][4] = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,0,0,0}
    };
    cout<<compute_Area(arr,4);

    return 0;
}