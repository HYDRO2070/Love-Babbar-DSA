// hashmap is an data structure which is used to store the data.
// why hashmap is prefered more is because of it's time complexity insertion,deletion,searching all the operation are faster than anyother data structure.
// hashmap is used various project in company level. 
// map is used to store key value pair in data;
// In hash table the insert,deletion, and searching are done O(1)
// in unodered map it print random element.


#include<bits/stdc++.h>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m;

    // Insertion using make pair
    pair<string,int> n = make_pair("hell",8);
    m.insert(n);

    // Insertion using indexing 
    m["mai"] = 9;

    // Accessing using index
    cout<<m["mai"]; 

    // Accessing using at key word
    cout<<m.at("mai");
    
    // printing map size
    cout<<m.size()<<endl;

    // finding count of a key
    cout<<m.count("mai");

    // deleting a key value
    m.erase("mai");
    cout<<m.size()<<endl;

    // printing all the element of the map
    for(auto i : m){
        cout<<i.first<<endl;
        cout<<i.second<<endl;
    }

    // using iterator
    // unordered_map<string,int>::iterator it = m.begin();

    // using auto key word
    auto it = m.begin();
    while(it != m.end()){
        cout<<it->first<<endl;
        cout<<it->second<<endl;
        it++;
    }

    return 0;
}