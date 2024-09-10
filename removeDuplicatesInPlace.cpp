#include<iostream>
#include<vector>

using namespace std;

//REMOVE DUPILCATE FROM SORTED ARRAY

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4,4,4,4,5,5};

    int i = 0; //points to unique element
    for(int j=i+1; j< arr.size(); j++)
    {
        // j is used to iterate

        if(arr[i]!=arr[j])
        {
            arr[i+1] = arr[j];
            i++; 
        }

        
    }

    //Fill 0 to mark empty space
    for(int k=i+1; k< arr.size(); k++)
        arr[k]=0;


    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    

    return 0;
}
