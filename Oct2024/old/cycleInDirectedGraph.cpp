#include<iostream>
#include<vector>

using namespace std;

/*

    1-->2-->3-->4-->5-->6
        |   |-->7-->|
        |
        |--<---8<-----------| 
               |----->9--->10

*/

bool dfs(int src, int parent, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& pathVisited){
    visited[src] = 1;
    pathVisited[src] = 1;

    for(auto neighbour : adjList[src]){
        if(!visited[neighbour]){
            if(dfs(neighbour, src, adjList, visited, pathVisited)) return true;
        }else{
            if(pathVisited[neighbour]){
                return true;
            }
        }
    }

    pathVisited[src] = 0;
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> adjList = {
                                   {},
                                   {2},
                                   {3},
                                   {4,7},
                                   {5},
                                   {6},
                                   {},
                                   {5},
                                   {2,9},
                                   {10},
                                   {8}
                                  };

    int n = adjList.size(); // 11

    vector<int> visited(n, 0);
    vector<int> pathVisited(n, 0);

    for(int i=1; i<n; i++){
        if(!visited[i]){
            if(dfs(i, -1, adjList, visited, pathVisited)){
                cout << "cycle detected";
                break;
            }
        }
    }

    return 0;
}
