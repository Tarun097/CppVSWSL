#include<iostream>
#include<vector>

using namespace std;

int MaxPointsOnDayUsingDP(int n, int lastTask, vector<vector<int>> dailyTasks, vector<vector<int>> dp){
    if(n==0){
        
        int maxi = 0;

        for(int task=0; task<3; task++){
            
            if(task!=lastTask){
                maxi = max(maxi, dailyTasks[n][task]);
            }

        }

        return maxi;

    }

    if(dp[n][lastTask]!=-1) return dp[n][lastTask];

    int maxi = 0;

    for(int task=0; task<3; task++){
        
        if(task!=lastTask){
            int points = dailyTasks[n][task] + MaxPointsOnDayUsingDP(n-1, task, dailyTasks, dp);
            maxi = max(maxi, points);
        }
    }

    return dp[n][lastTask] = maxi;

}

int MaxPointsOnDay(int n, int lastTask, vector<vector<int>> dailyTasks){
    if(n==0){
        
        int maxi = 0;

        for(int task=0; task<3; task++){
            
            if(task!=lastTask){
                maxi = max(maxi, dailyTasks[n][task]);
            }

        }

        return maxi;

    }

    int maxi = 0;

    for(int task=0; task<3; task++){
        
        if(task!=lastTask){
            int points = dailyTasks[n][task] + MaxPointsOnDay(n-1, task, dailyTasks);
            maxi = max(maxi, points);
        }
    }

    return maxi;

}


int main(int argc, char const *argv[])
{
    vector<vector<int>> dailyTasks = { 
                                        {2,1,3},
                                        {3,4,6},
                                        {10,1,6},
                                        {8,3,7}
                                     };

    int n = dailyTasks.size();
    int totalTasks = 4; // last task is NOT done task

    
    cout << MaxPointsOnDay(3, 3, dailyTasks)  << endl;

    vector<vector<int>> dp(n, vector<int>(totalTasks, -1));

    cout << MaxPointsOnDayUsingDP(3,3,dailyTasks, dp) << endl;


    return 0;
}
