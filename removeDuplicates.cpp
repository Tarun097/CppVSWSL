#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,1,3,1,1,3,2,5};

    std::set<int> uniqueArr ;

    for(int i = 0; i< arr.size(); i++)
    {
        uniqueArr.insert(arr[i]);
    } 


    int k = 0;
    for (auto &&i : uniqueArr)
    {
        arr[k] = i;
        k++;
    }

    for(int i=k; i< arr.size(); i++)
    {
        arr[i]=0;
    }
    
    
    for (auto &&i : arr)
    {
        cout << i << " "; 
    }
    
    

    return 0;
}