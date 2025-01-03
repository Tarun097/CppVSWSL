#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {3,1,2,3,4,5};

    for(vector<int>::iterator i = arr.begin(); i< arr.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;

    std::sort(arr.begin(), arr.end());

    for(vector<int>::iterator i = arr.begin(); i< arr.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}
