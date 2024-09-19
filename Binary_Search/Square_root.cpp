#include<iostream>
using namespace std;
int squareroot(int num){
    int left = 0;
    int right = num;
    long long int mid = left + (right - left) / 2;
    while(left <= right){
        // if(mid*mid == num){
        //     return mid;
        // }
        if(mid * mid > num){
            right = mid - 1;
        }
        else{
            left= mid + 1;
        }
        mid = left + (right - left) / 2;
    }
    return left-1;
}
double fullsol(int num,int till,int sol){
    if(sol * sol == num){
        return sol;
    }
    double kuch = 1;
    double ans = sol;
    for(int i = 0;i < till;i++){
        kuch = kuch /10;
        ans = ans + kuch;
        while(ans * ans < num){
            ans = ans + kuch;
        }
        ans = ans - kuch;
    }
    return ans;
}
int main(){
    int num = 99;
    cout<<fullsol(num,8,squareroot(num));
    return 0;
}