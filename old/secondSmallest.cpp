#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {-3,-1,0,6,1,2,3,4,5, -10};

    int smallest = arr[0];
    int secondSmallest = arr[1];

    for(int i=2; i<arr.size(); i++)
    {
        if(smallest>arr[i])
        {
            int temp = smallest;
            smallest = arr[i];
            secondSmallest = temp;
        }
        else if(secondSmallest> arr[i])
        {
            secondSmallest = arr[i];
        }
    }

    cout << "smallest : " << smallest << endl;
    cout << "second smallest : " << secondSmallest << endl;


    return 0;
}
