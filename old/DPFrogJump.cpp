#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

int energyForStep(int n, vector<int>& energy){
    
    if(n==0) return 0;

    //energy required to go from n to n-1 step
    int left = energyForStep(n-1, energy) + abs(energy[n]- energy[n-1]);

    //energy required to go from n to n-2 step
    int right = INT_MAX;
    if(n>1)
        right = energyForStep(n-2, energy) + abs(energy[n]- energy[n-2]);
    
    return min(left, right);
}

//avoids overlapping sub problems
int energyForStep(int n, vector<int>& energy, vector<int>& dp){
    
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];

    //energy required to go from n to n-1 step
    int energyForStep1 = energyForStep(n-1, energy) + abs(energy[n]- energy[n-1]);

    //energy required to go from n to n-2 step
    int energyForStep2 = INT_MAX;
    if(n>1)
        energyForStep2 = energyForStep(n-2, energy) + abs(energy[n]- energy[n-2]);
    
    return dp[n] = min(energyForStep1, energyForStep2);
}

int energyForStepWithTab(int n, vector<int>& energy){

    vector<int> dp(energy.size()+1, -1);    

    dp[0] = 0;

    for(int i=1; i<=n; i++){

        int fs = dp[i-1] + abs(energy[i]- energy[i-1]);
        int ss = INT_MAX;

        if(i>1){
            ss = dp[i-2] + abs(energy[i]- energy[i-2]);
        }

        dp[i] = min(fs, ss);
    }

    return dp[n];
}


int energyForStepWithTabAndSpaceOptimization(int n, vector<int>& energy){

    int prev = 0;
    int prev2 = 0;

    for(int i=1; i<=n; i++){

        int fs = prev + abs(energy[i]- energy[i-1]);
        int ss = INT_MAX;

        if(i>1){
            ss = prev2 + abs(energy[i]- energy[i-2]);
        }

        int current = min(fs, ss);
        prev2 = prev;
        prev = current;
    }

    return prev;
}


/*
                f(3) //40

         f(2)//0     f(1) //40

   f(1) // 40 f(0) //0        f(0) //0

f(0) // 0

*/


int main(int argc, char const *argv[])
{
    vector<int> steps = {10,50,30,10,50};

    //10 to 30 = 20
    //30 to 10 = 20
    // ans = 40
    

    // cout<< energyForStep(3, steps) << endl;

    // vector<int> dp(steps.size()+1, -1);

    // //frog can take 1 step or 2 steps
    // //energy required in taking 1 step from i to j is step[i]-step[j]

    // cout << energyForStep(3, steps, dp) << endl;

    // cout << energyForStepWithTab(3, steps) << endl;

    cout << energyForStepWithTabAndSpaceOptimization(4, steps) << endl;

    return 0;
}
