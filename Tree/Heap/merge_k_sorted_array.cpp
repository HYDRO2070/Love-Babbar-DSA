#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int column;

    Node(int da,int c,int r){
        this->column = c;
        this->row = r;
        this->data = da;
    }
};
class compare{
    public:
    bool operator()(Node *a,Node *b){
        return a->data > b->data;
    }
};


void print(vector<int> arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> solve(int arr[][4],int n,int m){
    priority_queue<Node*,vector<Node*>,compare> minheap;
    vector<int> ans;
    for(int i = 0;i < n;i++){
        Node *temp = new Node(arr[i][0],i,0);
        minheap.push(temp);
        // cout<<minheap.size()<<endl;
    }

    while(minheap.size() >= 1){
        // cout<<"Hhehehe"<<endl;
        Node *temp = minheap.top();
        minheap.pop();
        ans.push_back(temp->data);
        if(temp->row +1 < m){
            Node *tem = new Node(arr[temp->column][temp->row +1],temp->column,temp->row +1);
            minheap.push(tem);
        }
    }
    return ans;
}


int main(){
    int arr[4][4] = {
        {1,5,8,9},
        {2,4,10,14},
        {12,15,18,20},
        {21,27,32,54}
    };
    print(solve(arr,4,4));
    return 0;
}