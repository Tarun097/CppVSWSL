#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void swapItemsAtIndices(vector<int>& arr, int i, int j){
    if(i>j) return;

    swap(arr[i], arr[j]);

    swapItemsAtIndices(arr, i+1, j-1);
}

void reverseArray(vector<int>& arr){
    int i = 0;
    int j = arr.size()-1;

    while(i<j){

        swap(arr[i], arr[j]);

        i++;
        j--;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4,5};
    //swapItemsAtIndices(arr, 0, arr.size()-1);

    reverseArray(arr);

    for(auto i : arr){
        cout << i << " ";
    }

    return 0;
}
