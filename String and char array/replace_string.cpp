#include<iostream>
#include<cstring>
using namespace std;
int len(char arr[]){
    int count = 0;
    for(int i = 0;arr[i]!='\0';i++){
        count++;
    }
    return count;
}
string replace(char arr[],int l){
    string temp = "";
    for(int i = 0;i<l;i++){
        if(arr[i] == ' '){
            temp += "@40";
        }
        else{
            temp += arr[i];
        }
    }
    return temp;
}
int main(){
    char arr[30];
    cin.getline(arr,30);
    cout<<replace(arr,len(arr));
    return 0;
}