#include<bits/stdc++.h>
using namespace std;


int kth_sum(int *arr,int size,int k){
    priority_queue<int,vector<int>,greater<int> > pq;
    // vector<int> s;
    for(int i = 0;i < k;i++){
        pq.push(INT_MIN);
    }
    for(int i = 0;i < size;i++){
        int sum = 0;
        for(int j = i;j < size;j++){
            sum += arr[j];
            if(sum > pq.top()){
                pq.pop();
                pq.push(sum);
            }
            // s.push_back(sum);
        }
    }
    // sort(s.begin(),s.end());
    // for(int i = 0;i<s.size();i++){
    //     cout<<s[i]<<" ";
    // }
    // cout<<endl;
    // return s[s.size()-k];
    return pq.top();
}


int main(){
    
    int arr[5] = {3,-2,5};
    cout<<kth_sum(arr,3,3);
    return 0;
}