// Below Are the Important Keywords >
        // #define -> we use this keyword to define/create a macro.macro is a pease of code which can be replcae by the macro in the program.it can'nt be change. and it do'nt take any space in the memory.
        // Gobal Variable -> Through Global Variable We can share variable with different Function.the Gobal is define outside all the function or below header file.
        // Local Variable -> Its Life span Is only in the given Bracket only. and after it will Die or we can say it will distory.
        // Inline Function -> NO extra memory use and no function call.(one line only)
        // tercary Operator -> using if else in s single lIne.
        // default args -> we can define a default value in the function. and we have to write the default in the right most part.



#include<bits/stdc++.h>
using namespace std;
// #define pi 3.14
// int gol = 12;
// inline int getmax(int &a,int &b){
//     return (a>b)?a:b;
// }
void print(int arr[],int size,int st = 1){
    for(int i =st;i < size;i++){
        cout<<arr[i];
    }
}
int main(){
    // cout<<pi;
    // cout<<gol<<endl;
    // int a = 0;
    // int b = 3;
    // cout<<getmax(a,b);
    int arr[4] = {1,2,4,5};
    int size = 4;
    print(arr,size);
    return 0;
}