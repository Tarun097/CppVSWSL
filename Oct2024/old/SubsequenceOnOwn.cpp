#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

int getMaxSumFromSubsequenceTill(int n, int arr[]){

    if(n == 0) return arr[0];
    if(n == 1) return arr[1];

    int pick = arr[n] + getMaxSumFromSubsequenceTill(n-2, arr);
    int notPick = 0 + getMaxSumFromSubsequenceTill(n-1, arr);

    return max(pick, notPick);
}


int getMaxSumFromSubsequenceTill(int n, int arr[], vector<int>& dp){

    if(n == 0) return arr[0];
    if(n == 1) return arr[1];

    if(dp[n]!=-1) return dp[n];

    int pick = arr[n] + getMaxSumFromSubsequenceTill(n-2, arr);
    int notPick = 0 + getMaxSumFromSubsequenceTill(n-1, arr);

    return dp[n] = max(pick, notPick);
}

int getMaxSumFromSubsequenceTillUsingTabulation(int n, int arr[]){

    vector<int> dp(n+1, -1);
    dp[0] = arr[0];
    dp[1] = arr[1];

    for(int i=2; i<=n; i++){
        int pick = arr[i] + dp[i-2];
        int notPick = 0 + dp[i-1];

        dp[i] = max(pick, notPick);
    }

    return dp[n];
}

int getMaxSumFromSubsequenceTillUsingTabulationAndSpaceOptimization(int n, int arr[]){

    int prev2 = arr[0];
    int prev = arr[1];

    int current = INT_MIN;

    for(int i=2; i<=n; i++){
        int pick = arr[i] + prev2;
        int notPick = 0 + prev;

        current = max(pick, notPick);
        prev2 = prev;
        prev = current;
    }

    return prev;
}



int main(int argc, char const *argv[])
{
    int arr[] = {1,3,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << getMaxSumFromSubsequenceTill(3, arr) << endl;

    vector<int> dp(n+1, -1);

    cout << getMaxSumFromSubsequenceTill(3, arr, dp) << endl;

    cout << getMaxSumFromSubsequenceTillUsingTabulation(3, arr) << endl;

    cout << getMaxSumFromSubsequenceTillUsingTabulationAndSpaceOptimization(3, arr) << endl;

    return 0;
}