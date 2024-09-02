#include <iostream>
using namespace std;

// Arrays are a data structure which store data in a continuous manner.
// Arrays are of a fixed size which needs to be declared at initialization
//

int main()
{
    // array declaration and initialization
    int arr[5] = {1, 2, 3, 4, 5};

    // find the size of an array
    int size = sizeof(arr) / sizeof(arr[1]);
    cout << "The size of array is :" << size << endl;

    // loop through an array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}