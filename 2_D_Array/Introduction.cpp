#include<iostream>
using namespace std;
// bool linearSearch(int arr[][2],int r,int c,int t){
//     for(int i =0;i<2;i++){
//         for(int j =0;j<2;j++){
//             if(arr[i][j] == t){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

void rowsum(int arr[][3],int r,int c){
    int index = -1;
    int max= 0;
    for(int i =0;i<r;i++){
        int sum = 0;
        for(int j =0;j<c;j++){
            sum +=arr[i][j];
            // sum +=arr[j][i];
        }
        if(max < sum){
            max = sum;
            index = i;
        }
    }
        cout<<index + 1<<endl;
}
int main(){
    int arr[3][3];
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    // for(int i =0;i<2;i++){
    //     for(int j =0;j<2;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<linearSearch(arr,2,2,4);
    rowsum(arr,3,3);
    return 0;
}