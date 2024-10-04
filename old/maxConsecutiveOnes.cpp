#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,1,0,1,1,1,0,1,1,1,1};
    int maxOnes = 0;
    int consecCount = 0;

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]==1)
        {
            consecCount = consecCount + 1;

            if(consecCount > maxOnes)
                maxOnes = consecCount;
        }
        else
            consecCount = 0;
    }

    cout << maxOnes << endl;

    return 0;
}
