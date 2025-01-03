#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

/*      
           1----------2         7
          /|           \       / \
         / |            \     /   \
        0  |             \   /     |
         \ |              \ /      |
          \|               |       |
           3----4----5-----6-------8

*/


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


    int n = adjList.size(); //9

    vector<int> distance(n, INT_MAX);

    queue<pair<int,int>> q;

    int src = 0;
    distance[src] = 0;

    q.push({src,0}); //node, distance

    while (!q.empty())
    {
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();

        for(auto adjNode : adjList[node]){
            if(dis+ 1 < distance[adjNode]){
                distance[adjNode] = dis+1;
                q.push({adjNode,distance[adjNode]});
            }
        }
    }

    for(auto i : distance){
        cout << i << " ";
    }
    
    return 0;
}
