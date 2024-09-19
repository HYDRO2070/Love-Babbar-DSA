// #include<bits/stdc++.h>
// using namespace std;
// int getsum(int *arr,int n){
//     int sum = 0;
//     for(int i = 0;i < n;i++){
//         sum += arr[i];
//     }
//     return sum;
// }
// int main(){
//     // char *p = new char;
//     // *p = '4';
//     // (*p)++;
//     // cout<<*p<<endl;
//     // free(p);
//     int n;
//     cin>>n;
//     int *arr = new int[n];
//     for(int i = 0;i < n;i++){
//         cin>>arr[i];
//     }
//     cout<<getsum(arr,n)<<endl;
//     delete []arr;
//     cout<<getsum(arr,n);
//     return 0;
// }


// difference between Staic and Dynamic allocation
// -> if an array is created in static memory an it only use static memory but un dyamic it use bith staic and heap memory.
// -> int arr[40] and int *arr = new arr[40]
// -> 40 *4 = 1600 and 4 + 40*4 = 1604;
// -> In static memory the memory get release automatically. but in dyanmic allocation we have to clear the memory manularlly.

// part - 2
// creating 2d array using dyanmic allocation

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//         int n,m;
//         cin>>n>>m;
//         int **arr = new int*[n];
//         for(int i = 0;i < n;i++){
//             arr[i] = new int[m];
//         }
//         for(int i = 0;i < n;i++){
//             for(int j = 0;j < m;j++){
//                 cin>>arr[i][j];
//             }
//         }
//         for(int i = 0;i < n;i++){
//             for(int j = 0;j < m;j++){
//                 cout<<arr[i][j];
//             }
//         }

//         for(int i = 0;i < n;i++){
//             delete []arr[i];
//         }
//         delete []arr;
//     return 0;
// }