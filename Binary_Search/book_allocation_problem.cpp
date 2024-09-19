#include<iostream>
using namespace std;

// // DOne by my Self
// int ispossible(int arr[],int size,int num,int limit){
//     int ans[10] = {0};
//     int i = 0;
//     int j = 0;
//     int maxi = 0;
//     // cout<<endl;
//     while(j < size && i < num){
//         // cout<<j<<" "<<size;
//         if(ans[i] + arr[j] == limit){
//         // cout<<"-"<<endl;
//             ans[i] += arr[j];
//             maxi = max(maxi,ans[i]);
//             i++;
//             j++;
//         }
//         else if(ans[i] + arr[j] < limit){
//         // cout<<"--"<<endl;
//             ans[i] += arr[j];
//             j++;
//         }
//         else if(ans[i] + arr[j] > limit){
//             if(arr[i] == 0){
//                 return 0;
//             }
//             maxi = max(maxi,ans[i]);
//             i++;
//             if(i == num){
//                 return 0;
//             }
//         }
//     }
//     if(i == num && j != size-1){
//         // cout<<"   "<<maxi<<endl;
//         return 0;
//     }
//     cout<<maxi<<endl;
//     return maxi;
// }

//Solve by Lovebabar
bool ispossible(int arr[],int size,int num,int limit){
    int stdcount = 1;
    int pagesum = 0;
    for(int i = 0;i<size;i++){
        if(pagesum + arr[i] <= limit){
            pagesum += arr[i];
        }
        else{
            stdcount++;
            if(stdcount > num || arr[i] > limit){
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}

int bookall(int book[],int size,int num,int sum){
    int left = 0;
    int right = sum;
    int mid = left + (right - left) / 2;
    int ans = -1;
    while(left <= right){
    // int dec = ispossible(book,size,num,mid);
    //         // cout<<dec<<" "<<mid<<endl;
    //     if(dec){
    //         ans = min(dec,ans);
        if(ispossible(book,size,num,mid)){
            ans = mid;

            right = mid -1;
        }
        else{
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }
    return ans;
}
int sumall(int arr[],int size){
    int sum = 0;
    for(int i = 0;i < size;i++){
        sum += arr[i];
    }
    return sum;
}
int main(){
    int book[] = {12,34,67,90};
    int size = sizeof(book) / sizeof(int);
    int num = 2;
    
    cout<<bookall(book,size,num,sumall(book,size));
    return 0;
}