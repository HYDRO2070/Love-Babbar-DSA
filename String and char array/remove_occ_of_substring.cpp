#include<iostream>
using namespace std;
// string replacesubstring(string arr,string sub){
//     int i = 0,j = 0,k = 0;
//     int flag = 0;
//     while(j < arr.length()){
//         if(arr[j] == sub[k]){
//             i = j;
//             while(arr[i] == sub[k] && arr[i] != '\0'){
//                 k++;
//                 i++;
//             }
//             if(k == sub.length()){
//                 // arr.replace(j,sub.length(),"");
//                 arr.erase(j,sub.length());
//                 flag = 1;
//             }
//             // arr[j-1] = '\0';
//             if(flag == 1){
//                 flag = 0;
//                 j--;
//             k=0;
//             continue;
//             }
            
//         }
//         j++;
//         k = 0;
//     }
//     return arr;
// }

string replacesubstring(string arr,string sub){
    while(arr.length() != 0 && arr.find(sub) < arr.length()){
        arr.erase(arr.find(sub),sub.length());
    }
    return arr;
}
int main(){
    // string name = "my name name is name";
    string name = "daabcbaabcbc";
    // string name = "axxxxyyyyb";
    // name.replace(3,4,"");
    cout<<replacesubstring(name,"abc");
    return 0;
}