#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4,5,1,3,3,4};

    set<int> mySet(arr.begin(), arr.end());

    for (auto &&i : mySet)
    {
        cout << i << " "; 
    }
    

    return 0;
}