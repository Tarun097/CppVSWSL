#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    std::vector<int> arr = {1,2,3,0,0,4,4,5,0,1};

    int j = -1;
    
    for(int i=0; i< arr.size(); i++)
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }

    for(int i=j+1; i < arr.size(); i++)
    {
        if(arr[i]!=0)
        {
            arr[j] = arr[i];
            arr[i] = 0;
            j++;
        }
    }
    
    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    


    return 0;
}
