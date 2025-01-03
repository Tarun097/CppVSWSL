#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

/*

    Undirected graph - unit distance between each node

   0----1-----2--    /---7--\
    \   |        \  /        \
     ---3--4--5--- 6 ----------8

*/

void bfs(int src, int n, vector<vector<int>>& adjList, vector<int>& distance){

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adjList[node]){

            if(distance[node] + 1 < distance[it]){
                distance[it] = distance[node] + 1;
                q.push(it);
            }

        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> adjList = {
                                    {1,3},
                                    {0,2,3},
                                    {1,6},
                                    {0,4},
                                    {3,5},
                                    {4,6},
                                    {2,5,7,8},
                                    {6,8},
                                    {6,7}
                                  };

    int n = adjList.size();

    vector<int> distance(n, INT_MAX);
    int src = 0;
    distance[src] = 0;

    bfs(src, n, adjList, distance);

    for(auto it : distance){
        cout << it <<  " ";
    }
                        
    return 0;
}
