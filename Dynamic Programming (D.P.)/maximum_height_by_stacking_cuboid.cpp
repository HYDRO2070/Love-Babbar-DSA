// we have been given n cuboid with length L,width W,and height H. we have to determine the maximum high by stacking the cube one upon one. the above cube must be in small compare to the below cube in (L,H,W).

// approach : 
    // firstly sort the demension of each cuboid
    // now sort the vector of the cuboid on the bases of the first element.
    // now solve longest incresing subsequence



#include<bits/stdc++.h>
using namespace std;

int find(vector<vector<int>> &arr){
    int n = arr.size();
    for(auto &nums : arr){
        sort(nums.begin(),nums.end());
    }
    sort(arr.begin(),arr.end());
    vector<int> ans;
    ans.push_back(arr[0][0] * arr[0][1]);

    for(int i = 1;i < n;i++){
        int temp = arr[i][0] * arr[i][1];
        if(temp > ans.back()) ans.push_back(temp);
        else{
            int index = lower_bound(ans.begin(),ans.end(),temp) - ans.begin();
            ans[index] = temp;
        }
    }
    return ans.size();
}


int main(){
    vector<vector<int>> arr = {{50,45,20},{95,37,53},{45,23,12}};
    cout<<find(arr)<<endl;
    return 0;
}