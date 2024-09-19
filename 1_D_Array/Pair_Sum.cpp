#include<iostream>
using namespace std;
void pairsum(int arr[],int target,int size){
    int i = 0;
    int j = i + 1;
    int count = 0 ;
    while(i<size){
        count++;
        if(j<size){
            if(arr[i] + arr[j] == target){
                cout<<min(arr[i],arr[j])<<","<<max(arr[i],arr[j]);
                cout<<endl;
            }
            j++;
        }
        else{
            i++;
            j = i + 1;
        }
    }
    cout<<count;
}
int main(){
    int arr[] = {1,2,3,4,5};
    int target = 5;
    int size = sizeof(arr)/sizeof(int);
    pairsum(arr,target,size);
    return 0;
}