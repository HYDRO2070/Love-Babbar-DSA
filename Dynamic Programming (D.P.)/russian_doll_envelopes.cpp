// in thsi question we have been given the size H and W which are height and width of the envelopes and we have to determine how many envelopes can be one inside other.

#include<bits/stdc++.h>
using namespace std;

// void print(vector<vector<int>> &data){
//     cout<<"[";
//     for(auto arr : data){
//         cout<<"["<<arr[0]<<", "<<arr[1]<<"]";
//     }
//     cout<<"]"<<endl;

// }

int find(vector<vector<int>> &data){
    // print(data);
    // sort(data.begin(),data.end());
    // print(data);
    // int n = data.size();
    // vector<int> arr(n,0);
    // for(int i = 0;i < n;i++){
    //     arr[i] = data[i][1];
    // }
    // return 0;
}


int main(){
    vector<vector<int>> data = {{5,4},{6,4},{6,7},{2,3}};
    cout<<find(data)<<endl;
    return 0;
}


// int main() {
//     // Define the vector
//     std::vector<std::pair<int, int>> vec = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};

//     // Sort based on the second element
//     std::sort(vec.begin(), vec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
//         return a.second < b.second;
//     });

//     // Print the sorted vector
//     for (const auto& p : vec) {
//         std::cout << "{" << p.first << ", " << p.second << "} ";
//     }

//     return 0;
// }