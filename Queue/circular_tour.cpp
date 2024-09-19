// It is an important Question.

#include<bits/stdc++.h>
using namespace std;

// int find(vector<int> p,vector<int> d){
//     vector<int> q;
//     int front = 0;
//     int rear = 0;
//     int temp = 0;
//     for(int i = 0;i < p.size();i++){
//         q.push_back(p[i] - d[i]);
//     }
//     while(front != rear+1){
//         temp += q[rear];
//         cout<<front<<" "<<rear<<" "<<temp<<endl;
//         if(temp < 0){
//             rear++;
//             front = rear;
//             temp = 0;
//         }
//         else{
//             rear++;
//             rear = (rear + p.size()) % p.size();
//         }
//         if(rear+1 == front){
//             return front;
//         }
//     }
// }

// we can optimzie the above code by sorting before value for after n. so we have to traverse only one time.


// optimize
int find(vector<int> p,vector<int> d){
    int de = 0;
    int bal = 0;
    int st = 0;
    for(int i = 0;i < p.size();i++){
        bal += p[i] - d[i];
        if(bal < 0){
            de += bal;
            st = i+1;
            bal = 0;
        }
    }
    if(de  + bal >= 0) return st;
    return -1;
}

int main(){
    vector<int> p;
    vector<int> d;
    p.push_back(6);
    p.push_back(7);
    p.push_back(4);
    p.push_back(10);
    p.push_back(6);
    p.push_back(5);
    d.push_back(5);
    d.push_back(6);
    d.push_back(7);
    d.push_back(8);
    d.push_back(6);
    d.push_back(4);
    cout<<find(p,d);
    return 0;
}