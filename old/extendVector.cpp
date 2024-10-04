#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr1 = {1,2,3,4};

    vector<int> arr2 = {5,6,7,8};

    arr1.insert(arr1.begin(), arr2.begin(), arr2.end());

    for(auto i : arr1){
        cout << i << " ";
    }

    cout << endl;

    // for(vector<int>::iterator it = arr1.begin(); it < arr1.end(); it++){
    //     cout << *it << " ";
    // }

    for(auto it = arr1.rbegin(); it < arr1.rend(); it++){
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}
