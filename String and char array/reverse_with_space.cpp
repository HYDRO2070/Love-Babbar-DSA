#include<iostream>
using namespace std;
int len(char arr[]){
    int count = 0;
    for(int i = 0;arr[i]!='\0';i++){
        count++;
    }
    return count;
}
void reverse(char name[],int s,int e){
    while(s<=e){
        swap(name[s],name[e]);
        s++;
        e--;
    }
}
void reversespace(char name[],int l){
    int i = 0;
    int till = 0;
    while(i <= l){
        if(name[i] == ' '){
            reverse(name,till,i-1);
            till = i + 1;
        }
        if(name[i] == '\0'){
            reverse(name,till,i-1);
            till = i + 1;
        }
        i++;
    }
}
int main(){
    char name[30] ="your name is kuch";
    // int i = 0;
    // while(n[i] != '\0'){
    //     cout<<n[i];
    //     i++;
    // }
    reversespace(name,len(name));
    cout<<name;
    return 0;
}