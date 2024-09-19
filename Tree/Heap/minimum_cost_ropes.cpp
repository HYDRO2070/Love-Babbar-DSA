#include<bits/stdc++.h>
using namespace std;

int min_cost(int*arr,int size){
    priority_queue<int,vector<int>,greater<int> > pq;
    int ans = 0;
    for(int i = 0;i < size;i++){
        pq.push(arr[i]);
    }

    while(pq.size() > 1){
        // cout<<"helooe"<<endl;
        int sum = 0;
        sum += pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        pq.push(sum);
        cout<<sum<<endl;
        ans +=sum;
    }
    return ans;
}

int main(){
    int arr[] = {4,3,2,6};
    cout<<min_cost(arr,4);
    return 0;
}