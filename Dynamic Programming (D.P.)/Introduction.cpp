// - dp - dynamic programming
// - what does dp mean?
//  - dp mean's solving the problem using the result of it's sub - problem.
//  - the great example for this is fabonacci series in which we have to find the nth term of the series. and for finding that term we have to traverse the bottom of the series where the base case is there and using that we calculate it further and return the result.
//  - firstly there are two method used in the dynamic programming which are follow :-
            // 1. top - down approach - it use the concept of recursion,memoisation
            // 2. bottom- up approach - it use the concept of tabulation
            // 3. it's for saving extra space which is done in the dp.
//  - using all three and default which is recursive solution are shown below.



#include<bits/stdc++.h>
using namespace std;

// recursive solution  complexity here time - O(N) and space - O(N)
// int fabonacci(int n){
//     // here the recursion is call for every element. and it consume all the space. but the main point is it call the function which has been call one  time before. it is not using the result my before.
//     if(n == 1 || n == 0) return n;
//     return fabonacci(n-1) + fabonacci(n-2);
// }


// DP using the top down approach complexity here time - O(N) and space - O(N)+O(N)
// in dp we create an extra array to store the result which can be used in the future.
// int fabonacci(int n,int *dp){
//     // here the recursion is call for every element. and it consume all the space. but the main point is it call the function which has been call one  time before. it is not using the result my before.
//     if(n == 1 || n == 0) return n;
//     dp[n] =  fabonacci(n-1,dp) + fabonacci(n-2,dp);
//     return dp[n];
// }



int main(){
    int n;
    cout<<"ENter the Term to be find :"<<endl;
    cin>>n;

    // // using recursive function call
    // cout<<fabonacci(n)<<endl;

    // using dp top-down function call
    // int dp[n+1];
    // cout<<fabonacci(n,dp)<<endl;

    // complexity here time - O(N) and space - O(N)
    // now the third solution which is bottom-up approach of dp which use the concept of tabulation form
    // which mean in this problem we are depended on the starting two values only so we can solve the problem in this manner
    // int dp[n+1];
    // // here we are storing the initial value which can be used in further operation
    // dp[0] = 0;
    // dp[1] = 1;
    // // loop is starting from 2 is because the 0th and 1th postion value has be initialized
    // for(int i = 2;i <= n;i++){
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // // printing the result
    // cout<<dp[n]<<endl;


    // complexity here time - O(N) and space - O(1) this is the most optimize solution
    // now we have seen all the possible solution now is the last thing. which is to optimize the space complexity
    // you would have notice that the problem is using the initial two value and storing it in third and repeating the same step after it. so we can solve it in this way also
    // int first = 0;
    // int second = 1;
    // int third = first + second;
    // for(int i = 3;i<=n;++i){
    //     first = second;
    //     second = third;
    //     third = first + second;
    // }
    // cout<<third<<endl;


    // this is the beginning of the dym=namic programming which is going to be very hard.
    // more file will come.

    return 0;
}