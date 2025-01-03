#include<iostream>
#include<algorithm>

using namespace std;

void rotateArray(int arr[], int len, int n)
{
    n = n%len;

    reverse(arr,arr+n);
    reverse(arr+n+1, arr+len);
    reverse(arr, arr+len);
}

void printArray(int arr[], int len)
{
    for(int i=0; i<len; i++)
        cout << arr[i] << " ";
    cout << endl; 
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    rotateArray(arr, len, 3);

    printArray(arr,len);

    return 0;
}
