#include<iostream>
#include<vector>

using namespace std;

//Only step of 1 and step of 2 are allowed

int NumberOfStepsToReachZeroFromN(int n){

    if(n==0) return 1; // let's say you are on step 2, using (n-2) you can reach 0 in 1 way
    if(n==1) return 1;  // in one way you from 1 to 0 in 1 step

    int stepsOnes = NumberOfStepsToReachZeroFromN(n-1);
    int stepsTwos = NumberOfStepsToReachZeroFromN(n-2); 

    return stepsOnes + stepsTwos;
}



int main(int argc, char const *argv[])
{

    /*
        to reach step 4
            1 1 1 1
            1 1 2
            2 1 1
            1 2 1
            2 2
    */

    cout << NumberOfStepsToReachZeroFromN(4) << endl;
    return 0;
}
