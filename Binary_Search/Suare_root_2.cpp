#include<iostream>
#include<math.h>
using namespace std;
double squareroot(int num){
    if(num < 0){
        return -1;
    }
    if(num == 0 || num == 1){
        return num;
    }
    double temp = num / 2.0;
    while(abs(temp * temp - num) > 0.0001){
        temp = (temp + num / temp) / 2.0;
    }
    return temp;
}
int main(){
    int num = 5;
    cout<<squareroot(num);
    return 0;
}