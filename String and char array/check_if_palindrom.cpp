#include<iostream>
using namespace std;
int len(char arr[]){
    int count = 0;
    for(int i = 0;arr[i]!='\0';i++){
        count++;
    }
    return count;
}
char tolower(char kuch){
    if(kuch >= 'a' && kuch <= 'z')
    return kuch;
    else{
        return kuch - 'A' + 'a';
        // return kuch - 'a' + 'A';
    }
}
bool palindrom(char name[],int l){
    if(l < 3){
        return false;
    }

    for(int i = 0;i<(l)/2;i++){
        if(tolower(name[i]) != tolower(name[l-1-i])){
            return false;
        }
    }
    return true;
}
int main(){
    char name[20];
    cin>>name;
    
    cout<<palindrom(name,len(name));
    return 0;
}