#include<iostream>
#include<vector>
using namespace std;
int getcount(vector<int> arr,int e){
    
    
    int val = arr[e];
    int count = 0;
    for(int i = 0;i<e;i++){
        if(arr[i] > (2ll*val)){
            count++;
        }
    }
    return count;
}
int pairs(vector<int> arr){
    // 1 2 3 2 3 1
    int count = 0;
    for(int i = 0;i < arr.size() - 1;i++){
        if(arr[i] >= arr[i+1]){
            count += getcount(arr,i+1);
        }
    }
    return count;
}
void printans(vector<int> arr){
    for(int i = 0;i< arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// int mergesort(vector<int>& arr,int s,int e){
//     if(s >= e)
//         return 0;
//     int mid = s + (e - s) / 2;
//     int count = mergesort(arr,s,mid) + mergesort(arr,mid+1,e);


//     int j = mid+1;
//     for(int i= s;i<=mid;++i){
//         while(j <= e && (long long)arr[i] > 2ll *arr[j])
//             ++j;
//             count += (j-(mid+1));
//             cout<<j<<endl;
//     }

//         vector<int> arr1(e - s + 1);
//         int left = s,right = mid + 1,k = 0;
//         while(left <= mid && right <= e){
//             if(arr[left] <= arr[right])
//                 arr1[k++] = arr[left++];
//             else
//                 arr1[k++] = arr[right++];
//         }
//         while(left <= mid){
//             arr1[k++] = arr[left++];
//         }
//         while(right <= e){
//             arr1[k++] = arr[right++];
//         }
//         printans(arr1);
//         for(int i =s;i<=e;++i){
//             arr[i] = arr1[i - s];
//         }
//         return count;
// }




int main(){
    vector<int> arr;
    arr.push_back(2147483647);
    arr.push_back(2147483647);
    arr.push_back(-2147483647);
    arr.push_back(-2147483647);
    arr.push_back(-2147483647);
    arr.push_back(2147483647);
    // arr.push_back(3);
    // arr.push_back(4);
    // arr.push_back(1);
    // cout<<mergesort(arr,0,arr.size()-1);
    
    cout<<pairs(arr);
    return 0;
}