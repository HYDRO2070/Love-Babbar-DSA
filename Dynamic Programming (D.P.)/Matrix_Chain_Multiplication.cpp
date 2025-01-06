// Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum. When two matrices of size m*n and n*p when multiplied, they generate a matrix of size m*p and the number of multiplications performed is m*n*p.

// Examples:
// Input: arr[] = {2, 1, 3, 4}
// Output: 20
// Explanation: There are 3 matrices of dimensions 2×1, 1×3, and 3×4, 
// Let the input 3 matrices be M1, M2, and M3. There are two ways to multiply ((M1 x M2) x M3) and (M1 x (M2 x M3)), 
// Please note that the result of M1 x M2 is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix.
// ((M1 x M2) x M3)  requires (2 x 1 x 3)  + (0) +  (2 x 3 x 4) = 30 
// (M1 x (M2 x M3))  requires (0)  + (1 x 3 x 4) +  (2 x 1 x 4) = 20 
// The minimum of these two is 20.


#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &arr){
    
}


int main(){
    vector<int> arr = {2, 1, 3, 4};
    cout<<find(arr);
    return 0;
}