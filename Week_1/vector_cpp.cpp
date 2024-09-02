#include<vector>
#include<iostream>
using namespace std;

// Arrays is of fixed size and the size cannot be increased during run time. So instead we can use vector
// 

int main() {
    // declaration and initialization
    vector<int> nums;

    for (int i = 0; i < 10; i++) {
        nums.push_back(i);
    }

    // iterate over a vector
    for (auto i : nums) {
        cout<<i<<endl;
    }

    // method on vector

    // size
    cout<<"Size of vector is "<<nums.size()<<endl;
    
    // delete last element
    nums.pop_back();

    // clears all vector
    //nums.clear();

    // check if vector is empty
    cout<<"Is vector empty"<<nums.empty()<<endl;

    // give the last element
    cout<<"Last element of vector is " << nums.back();

    return 0;
}