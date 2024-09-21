#include<iostream>
#include<vector>

using namespace std;

void printSubSequence(int index,int n, vector<int>& subsequence, int arr[]){
    
    if(index>=n){
        for(auto i : subsequence){
            cout << i << " ";
        }

        if(subsequence.size() == 0)
            cout << "{}";

        cout << endl;
        return;
    }
    
    subsequence.push_back(arr[index]);

    printSubSequence(index+1, n, subsequence, arr); //with

    subsequence.pop_back();

    printSubSequence(index+1, n, subsequence, arr); //without
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5};

    vector<int> subsequence;

    printSubSequence(0, 5, subsequence, arr);

    return 0;
}
