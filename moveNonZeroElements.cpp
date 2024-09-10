#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    std::vector<int> arr = {1,2,3,0,0,4,4,5,0,1};

    vector<int> temp;

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]!=0)
            temp.push_back(arr[i]);
    }

    for(int i=0; i<temp.size(); i++)
    {
        arr[i] = temp[i];
    }

    for(int i = temp.size(); i< arr.size(); i++)
    {
        arr[i] = 0;
    }
    
    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    

    return 0;
}
