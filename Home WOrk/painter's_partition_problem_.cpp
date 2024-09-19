#include<iostream>
using namespace std;
int sum(int arr[],int size){
    int sum= 0;
    for(int i = 0;i<size;i++){
        sum += arr[i];
    }
    return sum;
}
bool ispossible(int arr[],int size,int painter,int limit){
    int ptcount = 1;
    int time = 0;
    for(int i = 0;i< size;i++){
        if(time + arr[i] <= limit){
            time += arr[i];
        }
        else{
            ptcount++;
            if(ptcount > painter || arr[i] > limit){
                return false;
            }
            time = arr[i];
        }
    }
    return true;
}
int timerequired(int arr[],int size,int painter){
    int left = 0;
    int right = sum(arr,size);
    int mid = left + (right - left) / 2;
    int ans = -1;
    while(left <= right){
        if(ispossible(arr,size,painter,mid)){
            ans = mid;
            right = mid -1;
        }
        else{
            left = mid + 1;
        }
        mid = left + (right -left) / 2;
    }
    return ans;
}
int main(){
    int arr[] = {5,5,5,5};
    int painter = 2;
    int size = sizeof(arr) / sizeof(int);
    cout<<timerequired(arr,size,painter);
    return 0;
}