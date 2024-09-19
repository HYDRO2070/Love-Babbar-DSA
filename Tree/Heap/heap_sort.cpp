#include<bits/stdc++.h>
using namespace std;


// void solve(int *arr,int n,int i){
//     int la = i;
//     int left = 2*i;
//     int right = (2*i)+ 1;
//     if(left <= n && arr[la] < arr[left]){
//         la = left;
//     }
//     if(right <= n && arr[la] < arr[right]){
//         // cout<<"hello"<<endl;
//         la = right;
//     }
//     if(la != i){
//         swap(arr[la],arr[i]);
//         solve(arr,n,la);
//     }
// }

// void delet(int *arr,int &size){
//         if(size < 1) return;

//         swap(arr[1],arr[size]);
//         size--;
//         int i = 1;
//         while(i < size){
//             // cout<<"Hello1111"<<endl;
//             int temp = i;
//             // if(arr[i] > arr[2 * i] && arr[i] > arr[2 * i + 1]){
//             //     return ans;
//             // }
//             if( 2*i <= size  && arr[2 * i] > arr[i]){
//                 // cout<<"jjdjd"<<endl;
//                 // swap(arr[i],arr[2*i]);
//                 // i = 2 *i;
//                 temp = 2*1;
//             }
//             if( 2*i+1 <= size  && arr[2 * i + 1] > arr[i]){
//                 // cout<<"jj"<<endl;
//                 // swap(arr[i],arr[2*i +1]);
//                 // i = 2 *i + 1;
//                 temp =2 *i + 1; 
//             }
//             if(temp != i){
//                 swap(arr[i],arr[temp]);
//                 i = temp;
//             }
//             else{
//                 break;
//             }
//         }
// }

// void print(int *arr,int size){
//     for(int i = 0;i <= size;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }


// void heapify(int *arr,int &size){
//     // vector<int> ans(size);
//     for(int i = (size/2);i > 0;i--){
//         solve(arr,size,i);
//     }
//     int temp = size;
//     for(int i = 1;i <= size;i++){
//         // cout<<"yyyyyyy"<<endl;
//         // ans[i-1] = 
//         delet(arr,temp);
//     }
//     print(arr,size);
    
    
// }

int main(){


            //         54
            //     53      55
            // 52      50

    // int arr[6] = {-1,54,53,55,52,50};
    // int size = 5;
    // heapify(arr,size);

    // max heap
    // priority_queue<int> pq;    

    priority_queue<int,vector<int>,greater<int> > minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(9);
    minheap.push(2);
    minheap.push(-1);
    cout<<minheap.top();

    return 0;
}