#include<unordered_map>
#include<iostream>
using namespace std;

// Unordered Map stores data in key value pairs. 
// TC of u_map is O(1) for all operations
// TC of o_map is O(log n) for all operations

int main() {


    // declation of u_map
    unordered_map<int, string> u_map;

    // insert
    u_map.insert({1, "one"});
    u_map.insert(make_pair(2, "two"));
    u_map.insert(make_pair(3, "three"));
    u_map.insert(make_pair(4, "four"));
    u_map.insert(make_pair(5, "five"));

    // iterate through an map

    // for (auto i = u_map.begin(); i != u_map.end(); i++) {
    //     cout<<i->first<<i->second;
    // }

    for (auto iter : u_map) {
        cout<<iter.first << " " << iter.second<<endl;
    }
    
    // find the key
    auto it = u_map.find(1);
    if (it != u_map.end()) {
        cout<< it->second;
    } else {
        cout<< "Not found";
    }

    // delete a key
    it = u_map.find(3);
    u_map.erase(it);

    for (auto iter : u_map) {
        cout<<iter.first << " " << iter.second<<endl;
    }

    return 0;
}