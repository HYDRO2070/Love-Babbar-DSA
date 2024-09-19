// it is an complete binary tree with the property of heap order.
// there are two type of heap property ehich are :
            // max heap - parent is the max element
            // min heap - parent is the min element
// it will start from 1 index
// where i s current node
// the left element can be found using (2*i) formula
// the right element can be found using (2*i +1) formula
// to find parent we will use (i/2)
// we wil impliment using array

#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int *arr;
    int size;
    int mx;

    heap(int val){
        arr = new int[val];
        mx = val;
        size = 0;
        arr[size] = -1;
    }

    void insert(int val){
        if(size+1 > mx){
            cout<<"Overflow"<<endl;
            return;
        }
        size++;
        arr[size] = val;
        while(size > 1){
            int parent = size / 2;
            if(arr[parent] < arr[size]){
                swap(arr[parent],arr[size]);
            }
            else{
                return;
            }
        }
    }

    int delet(){
        if(size < 1) return -1;

        int ans = arr[1];
        arr[1] = arr[size];
        size--;
        int i = 1;
        while(i < size){
            
            if(arr[i] > arr[2 * i] && arr[i] > arr[2 * i + 1]){
                return ans;
            }
            if( 2*i <= size  && arr[2 * i] > arr[i]){
                // cout<<"jjdjd"<<endl;
                swap(arr[i],arr[2*i]);
                i = 2 *i;
            }
            if( 2*i+1 <= size  && arr[2 * i + 1] > arr[i]){
                // cout<<"jj"<<endl;
                swap(arr[i],arr[2*i +1]);
                i = 2 *i + 1;
            }
        }
        return ans;
    }

    void print(){
        for(int i = 1;i <= size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    heap h(5);
    h.insert(4);
    h.insert(2);
    h.insert(5);
    h.insert(1);
    h.print();
    cout<<h.size<<endl;
    cout<<h.delet()<<endl;
    cout<<h.size<<endl;
    h.print();
    return 0;
}