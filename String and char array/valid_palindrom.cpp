#include<iostream>
using namespace std;
bool valid(char a){
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')){
        return true;
    }
    return false;
}
char tolower(char kuch){
    if(kuch >= 'a' && kuch <= 'z')
    return kuch;
    else{
        return kuch - 'A' + 'a';
        // return kuch - 'a' + 'A';
    }
}
bool palindrom(string name){

    if(name.length() < 3){
        return false;
    }

    for(int i = 0;i<(name.length())/2;i++){
        if(tolower(name[i]) != tolower(name[name.length()-1-i])){
            return false;
        }
    }
    return true;
}
bool validpali(string name){
    string temp = "";
    for(int i = 0; i<name.length();i++){
        if(valid(name[i])){
            temp.push_back(name[i]);
        }
    }
    return palindrom(temp);
}
int main(){
    string name = "A 0 ,,,8,,9,, 0 A";
    
    cout<<validpali(name);
    return 0;
}