#include<iostream>
#include<vector>

using namespace std;

//1,2,3,4,5 - d = 3, n=5
//4,5,1,2,3 - arr

void printArray(int arr[], int len)
{
    for(int i=0; i<len ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotateArray(int arr[], int len, int d)
{
    d = d%len;

    //Store first d elements in temp array
    std::vector<int> tempStorage;
    for(int i=0; i<d; i++)
        tempStorage.push_back(arr[i]);

    int j=0;
    for(int i=d; i<len; i++)
    {
        arr[j]= arr[i];
        j++;
    }

    int l = len-d;
    for(int k=0; k<tempStorage.size(); k++)
    {
        arr[l] = tempStorage[k];
        l++;
    }

}


int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);

    cout<<"before rotating\n";
    printArray(arr, len);

    rotateArray(arr, len, 4);

    cout<<"after rotating\n";
    printArray(arr, len);


    return 0;
}
