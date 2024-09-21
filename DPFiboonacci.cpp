#include<iostream>
#include<vector>

using namespace std;

int fib(int n){
    if(n<=1) return n;

    return fib(n-1) + fib(n-2);
}

int fib(int n, vector<int>& dp){
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = fib(n-1) + fib(n-2);
}

//using tabulation : bottom-up

int fibUsingTab(int n, vector<int>& dp){

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int fibUsingTabSpaceOptimization(int n){

    int prev2= 0;
    int prev =1;

    if(n==0) return prev2;
    if(n==1) return prev;


    for(int i=2; i<=n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    return prev;
}


int main(int argc, char const *argv[])
{

    int n = 5;
    vector<int> dp(n+1, -1);

    // cout << fib(0) << endl;
    // cout << fib(1) << endl;
    // cout << fib(2) << endl;
    // cout << fib(3) << endl;
    // cout << fib(4, dp) << endl; // 0 ,1,1,2,3,5

    cout << fibUsingTab(4, dp) << endl; 

    cout << fibUsingTabSpaceOptimization(5);

    return 0;
}
