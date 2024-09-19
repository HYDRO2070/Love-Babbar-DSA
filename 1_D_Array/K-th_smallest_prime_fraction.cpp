// This Is Question for 10/05/2025 daily Question.

#include<bits/stdc++.h>
using namespace std;
void print(vector<int> arr){
    for(int i =0; i < arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
// vector<int> getfaction(vector<int> arr,int k){
//     // 1 2 3 5
//     // int a = -1;
//     // int b = -1;
//     // int i = 0;

//     vector<double> temp;
//     vector<int> ans;
//     // int j = arr.size()-1;
//     for(int i = 0;i<arr.size();i++){
//         for(int j = i+1;j<arr.size();j++){
//             // double n = double(arr[i])/(arr[j]);
//             // cout<<n<<endl;
//             // cout<<i<<" "<<j<<endl;
//             temp.push_back(double(arr[i])/(arr[j]));
//         }
//     }
//     sort(temp.begin(),temp.end());
//     // double p = temp[k-1];
//     for(int i = 0;i<arr.size();i++){
//         for(int j = i+1;j<arr.size();j++){
//             double n = double(arr[i])/(arr[j]);
//             if(temp[k-1] == n){
//                 ans.push_back(arr[i]);
//                 ans.push_back(arr[j]);
//                 return ans;
//             }
//         }
//     }
//     // print(temp);
//     return ans;
// }

vector<int> getfaction(vector<int> arr,int k){
    vector<int> wer;
    float ans = float(arr[0]) / arr[arr.size() - 1];
    if(k == 1){
        wer.push_back(arr[0]);
        wer.push_back(arr[1]);
    }
    float temp = 0;
    float temp1 = 0;
    k--;
    int i = 0;
    int j = arr.size() - 2;
    while(i < j){
        // cout<<"Reapet ho raha hai."<<endl;
        float g = float(arr[i]) / arr[j];
            // cout<<g<<endl;
        temp1 = g;
        if(temp != 0){
            if(temp > ans && temp < temp1){
            ans = temp;
            temp = temp1;
            // if(!(--k)){
            // }
            k--;
            }
            else if(temp1 < temp){
                ans = temp1;
                k--;
            }
            if(!k){
                // cout<<arr[i]<<" "<<arr[j]<<endl;
                wer.push_back(arr[i]);
                wer.push_back(arr[j]);
                // cout<<
            }
        }
        else{
            temp = temp1;
            if(k == 2){
                wer.push_back(arr[i]);
                wer.push_back(arr[j]);
                return wer;
            }
        }
        
        // else{
        //     temp1 = temp;
        // }
        if(j -1 == i){
            i++;
            // cout<<"HEloo"<<endl;
            j = arr.size() -1;
            continue;
        }
        j--;
    }
    cout<<temp<<" "<<k<<endl;
    return wer;
}
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    int k = 4;
    print(arr);
    vector<int> ans = getfaction(arr,k);
    print(ans);
    return 0;
}