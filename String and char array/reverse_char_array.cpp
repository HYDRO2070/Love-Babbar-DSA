#include<iostream>
using namespace std;
int len(char arr[]){
    int count = 0;
    for(int i = 0;arr[i]!='\0';i++){
        count++;
    }
    return count;
}
void reverse(char name[],int l){

    for(int i = 0;i<(l)/2;i++){
        // char temp = name[i];
        // name[i] = name[l-1-i];
        // name[l-1-i] = temp;
        swap(name[i],name[l-1-i]);
    }
}
int main(){
    char name[20];
    cin>>name;
    reverse(name,len(name));
    cout<<name;
    return 0;
}