#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr1 = {1,2,3,3,4,5};
    vector<int> arr2 = {1,3,3,5,5}; //i

    vector<int> common;

    int n1 = arr1.size();
    int n2 = arr2.size();
    int i=0;
    int j=0;

    while (i< n1 && j< n2)
    {
        if(arr1[i]== arr2[j])
        {
            common.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] > arr2[j])
            j++;
        else
            i++;
    }
    

    for (auto i : common)
    {   
        cout << i << " ";
    }
    

    return 0;
}
