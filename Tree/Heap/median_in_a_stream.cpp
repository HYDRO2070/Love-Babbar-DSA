#include<bits/stdc++.h>
using namespace std;

// bool issort(vector<int> &arr){
//     for(int i = 1;i < arr.size();i++){
//         if(arr[i] < arr[i-1]) return false;
//     }
//     return true;
// }


// solution of O(n2)
// int median(vector<int> &arr,int val){
//     arr.push_back(val);
//     for(int i = 0;i < arr.size()-1;i++){
//         for(int j = i+1;j < arr.size();j++){
//             if(arr[i] > arr[j]){
//                 swap(arr[i],arr[j]);
//             }
//         }
//     }
//     int size = arr.size();
//     for(int i =0;i<size;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     if(size&1){
//         return arr[size/2 + 1];
//     }
//     return (arr[size/2] + arr[size/2 - 1]) / 2;
// }


int signum(int a,int b){
    if(a == b) return 0;
    if(a > b) return 1;
    return -1;
}

void call_median(int element,priority_queue<int> &maxi,priority_queue<int,vector<int>,greater<int> > &mini,int &median){

    switch(signum(maxi.size(),mini.size())){
        case 0:if(element > median){
                    mini.push(element);
                    median = mini.top();
                }   
                else{
                    maxi.push(element);
                    median = maxi.top();
                }
                break;

        case 1:if(element > median){
                    mini.push(element);
                    median = (mini.top()+maxi.top()) / 2;;
                }
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                    median = (mini.top()+maxi.top()) / 2;;
                }
                break;
        case -1:if(element > median){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                    median = (mini.top()+maxi.top()) / 2;;
                }
                else{
                    
                    maxi.push(element);
                    median = (mini.top()+maxi.top()) / 2;;
                }
                break;
    }

}


// using heap data structure O(nlogn)
vector<int> find_median(vector<int> &arr){
    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int> > minheap;
    int median = 0;

    for(int i = 0;i < arr.size();i++){
        call_median(arr[i],maxheap,minheap,median);
        ans.push_back(median);
    }
    return ans;
}

void print(vector<int> arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
// 1 3 5 9 15

    vector<int> arr;
    arr.push_back(5);
    arr.push_back(15);
    arr.push_back(1);
    arr.push_back(3);
    print(find_median(arr));
    // cout<<median(arr,9);
    // cout<<median(arr,10);
    return 0;
}