#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr1 = {1,2,3,3,4};
    vector<int> arr2 = {1,2,5};

    vector<int> unionArray;

    int n1 = arr1.size();
    int n2 = arr2.size();

    int i=0;
    int j=0;

    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            if(unionArray.size() == 0 || unionArray.back() != arr1[i])
            {
                unionArray.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if(unionArray.size() == 0 || unionArray.back() != arr2[j])
            {
                unionArray.push_back(arr2[j]);
            }
            j++;

        }
    }

    while(i<n1)
    {
        if(unionArray.size() == 0 || unionArray.back() != arr1[i])
        {
            unionArray.push_back(arr1[i]);
        }
        i++;
    }

    while(j<n2)
    {
        if(unionArray.size() == 0 || unionArray.back() != arr2[j])
        {
            unionArray.push_back(arr2[j]);
        }
        j++;

    }

    for(int k=0; k<unionArray.size(); k++)
        std::cout << unionArray[k] << " ";    

    return 0;
}
