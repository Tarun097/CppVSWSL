#include<iostream>
#include<vector>

using namespace std;

void findSubsequence(int index, vector<int>& subsequence,int arr[], int n,  int requiredSum, int currentSum){

    if(index >= n){
        if(currentSum == requiredSum){
            //print subsequence
            for(auto i : subsequence){
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }

    subsequence.push_back(arr[index]);
    currentSum += arr[index];
    findSubsequence(index+1, subsequence, arr, n, requiredSum, currentSum);

    subsequence.pop_back();
    currentSum -= arr[index];
    findSubsequence(index+1, subsequence, arr, n, requiredSum, currentSum);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,1};

    vector<int> subsequence;

    int requiredSum = 2;
    int currentSum = 0;

    findSubsequence(0, subsequence, arr, 3, requiredSum, currentSum);

    return 0;
}
