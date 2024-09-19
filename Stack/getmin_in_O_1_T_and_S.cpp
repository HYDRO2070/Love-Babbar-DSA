#include<bits/stdc++.h>
using namespace std;
class ms{
    int *arr;
    int size = -1;
    int top = -1;
    int mini = INT_MAX;
    public:
    ms(int val){
        size = val;
        arr = new int[val];
    }
    void push(int val){
        if(top+1 >= size){
            cout<<"StackOverFlow"<<endl;
            return;
        }
        if(top == -1){
            mini = val;
            top++;
            arr[top] = val;
        }
        else if(mini > val){
            
            int temp = 2*val - mini;
            mini = val;
            top++;
            arr[top] = temp;
        }
        else{
            top++;
            arr[top] = val;
        }
    }
    void pop(){
        if(top == -1){
            cout<<"StackUnderFlow"<<endl;
            return;
        }
        if(arr[top] > mini){
            arr[top] = 0;
            top--;
        }
        else{
            int temp = 2*mini - arr[top];
            mini = temp;
            arr[top] = 0;
            top--;
        }
    }

    int getmin(){
        return this->mini;
    }

    void print(){
        for(int i = 0;i < size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    ms *s = new ms(6);
    s->push(5);
    cout<<s->getmin()<<endl;
    s->push(3);
    cout<<s->getmin()<<endl;
    s->push(8);
    cout<<s->getmin()<<endl;
    s->push(2);
    cout<<s->getmin()<<endl;
    s->push(4);
    cout<<s->getmin()<<endl;
    s->print();
    return 0;
}