#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr1 = {1,2,4,5};
    int n = 5;

    int xor1 = 0;
    int xor2 = 0;

    for(int i=0; i<n; i++)
    {
        xor1 = xor1^arr1[i];
        xor2 = xor2^(i+1);
    }

    cout <<  ( xor1^xor2 );

    return 0;
}
