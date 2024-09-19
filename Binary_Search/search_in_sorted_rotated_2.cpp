#include<iostream>
#include<vector>
using namespace std;
void printans(vector<int> arr){
    for(int i = 0;i< arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int removeall(vector<int>& arr){
    // int bitmap = 0;
    // int i = 0;
    // while(i < arr.size()){
    //     int mask = 1 << arr[i];
    //     if(bitmap & mask){
    //         cout<<arr[i]<<" ";
    //         arr.erase(1,2);
    //     }
    //     else{
    //         bitmap |= mask;
    //     }
    //     i++;
    // }
    int index = 0;
    for(int i = 1;i < arr.size();i++){
        if(arr[index] != arr[i]){
            arr[++index] = arr[i];
        }
    }
    // cout<<index<<endl;
    printans(arr);
    return index - 1;
}
int Binary(vector<int> arr,int s,int e,int t){
    int mid = s + (e - s) / 2;
    while(s <= e){
        if(arr[mid] == t){
            return mid;
        }
        else if(arr[mid] > t){
            e = mid -1;
        }
        else{
            s = mid +1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int search(vector<int> arr,int target){
    int size = removeall(arr);
    int left = 0;

    int right = size;
    cout<<right<<endl;
    int mid = left + (right - left) / 2;
    while(left < right){
        if(arr[mid] >= arr[0]){
            left = mid + 1;
        }
        else{
            right = mid;
        }
        mid = left + (right - left) / 2;
    }

    return (arr[left] <= target && arr[size] >= target) ? Binary(arr,left,(size),target) : Binary(arr,0,left-1,target);
}
int main(){
    vector<int> arr;
    // arr.push_back(2);
    // arr.push_back(5);
    // arr.push_back(6);
    // arr.push_back(0);
    // arr.push_back(0);
    // arr.push_back(1);
    // arr.push_back(2);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(13);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    int target = 13;
    // cout<<search(arr,target);
    printans(arr);
    cout<<search(arr,target);
    return 0;
}