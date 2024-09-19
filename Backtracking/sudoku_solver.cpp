#include<bits/stdc++.h>
using namespace std;

// complexity - 
            // time - O(9^m )    where m is no. of empty space
            // space - O(1)

bool issafe(int row,int col,int arr[][9],int val,int size){
    for(int i = 0;i < size;i++){
        if(arr[row][i] == val || arr[i][col] == val)
        return false;
        if(arr[3*(row / 3) + i/3][3*(col / 3) + i%3] == val)
        return false;
    }
    return true;
}


bool solve(int arr[][9],int size){
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            if(!arr[i][j]){
                for(int k = 1;k <= 9;k++){
                    if(issafe(i,j,arr,k,size)){
                        arr[i][j] = k;

                        // recursion
                        bool moresolution = solve(arr,size);
                        if(moresolution){
                            return true;
                        }
                        else{
                            // backtrack
                            arr[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;

}


int main(){
    int arr[9][9] = {
        {2, 0, 0, 3, 0, 0, 0, 0, 0},
        {8, 0, 4, 0, 6, 2, 0, 0, 3},
        {0, 1, 3, 8, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 2, 0, 3, 9, 0},
        {5, 0, 7, 0, 0, 0, 6, 2, 1},
        {0, 3, 2, 0, 0, 6, 0, 0, 0},
        {0, 2, 0, 0, 0, 9, 1, 4, 0},
        {6, 0, 1, 2, 5, 0, 8, 0, 9},
        {0, 0, 0, 0, 0, 1, 0, 0, 2}
    };

        cout<<"Non solution found"<<endl;
    if(solve(arr,9)){
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                cout<<arr[i][j] <<" ";
            }
            cout<<endl;
        }
            cout<<endl;
    }
    else{
        cout<<"Non solution found"<<endl;
    }

    return 0;
}