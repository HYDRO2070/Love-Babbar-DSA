// In this Question We ahve been Given Two array which stands for quality and wage of the worker for every ith value of an indiviual worker.
// so the condition is that we have create a (k(which will be given)) worker.
// every worker should be paid equally according to there wage and quality.
// we have to return the minimum amount to create the k paod group.
// Quality - [10,20,5] , Wage - [70,50,30] , k - 2
// output - 105.0000




#include<bits/stdc++.h>
using namespace std;

float mink(vector<int> quality,vector<int> wage,int k){
    float f = INT_MAX;
    int i = 0;
    for(int j = 0;j < wage.size();j++){
    float ans = 0;
    vector<int> temp;
    for(int i = j;i < wage.size();i++){
        temp.push_back(i);
        if(temp.size() == 1){
            ans += wage[i];
            // cout<<"he"<<endl;
            continue;
        }
        else{
            cout<<"--"<<ans<<i<<" "<<temp.size()<<endl;
            // cout<<endl;
            for(int j = 0;j < temp.size()-1;j++){
                if(quality[temp[temp.size()-1]] > quality[temp[j]]){
                    float n = quality[temp[temp.size()-1]] / float(quality[temp[j]]);
                    if((wage[temp[j]]) >= (wage[temp[temp.size()-1]] / n)){
                        ans += wage[temp[temp.size()-1]];
                        continue;
                    }
                    else{
                        temp.pop_back();
                        break;
                    }
                }
                else if(quality[temp[temp.size()-1]] < quality[temp[j]]){
            // cout<<i<<endl;
                    float n = float(quality[temp[j]]) / quality[temp[temp.size()-1]];
                    if((wage[temp[j]] / n) >= wage[temp[temp.size()-1]]){
                        ans += (wage[temp[j]] / n);
                        continue;
                    }
                    else{
                        temp.pop_back();
                        break;
                    }
                }
                else{
                    continue;
                }
            }
        }
        
        if(temp.size() == k){
            f = min(f,ans);
            // ans = 
            break;
        }
    }
    cout<<ans<<endl;
    if(temp.size() == k){

    f = min(f,ans);
    }
    }
    return f;
}


int main(){
    vector<int> quality;
    vector<int> wage;
    quality.push_back(10);
    quality.push_back(20);
    quality.push_back(5);
    wage.push_back(70);
    wage.push_back(50);
    wage.push_back(30);
    // quality.push_back(3);
    // quality.push_back(1);
    // quality.push_back(10);
    // quality.push_back(10);
    // quality.push_back(1);
    // wage.push_back(4);
    // wage.push_back(8);
    // wage.push_back(2);
    // wage.push_back(2);
    // wage.push_back(7);
    int k = 2;
    cout<<mink(quality,wage,k);
    return 0;
}