#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

/*      
      2-----5
     /       \
    1         7
     \       /
      3-----6
      |
      4


      1--3--4--5
      |
      2
      |
      6
*/

void detectCycleInGraph(int source , int n, vector<vector<int>> adjList){
    int visited[n+1] = {0};
    
    queue<pair<int,int>> q;

    q.push(make_pair(source,-1));
    visited[source] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode : adjList[node]){
            if(!visited[adjacentNode]){
                visited[adjacentNode]=1;
                q.push(make_pair(adjacentNode,node));
            }else if(adjacentNode != parent) //if already visted , and not parent, then it has cycle
            {
                cout << "\ncycle detected\n";
            }
        }        
    }
    
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> adjList = {
        {},
        {2,3},
        {1,5},
        {1,4,6},
        {3},
        {2,7},
        {3,7},
        {5,6}
    };

    int n = adjList.size();

    for(int i=1; i<n; i++){
        cout << i << " : ";
        for(auto k : adjList[i]){
            cout << k << ", ";
        }
        cout << endl;
    }

    //detectCycleInGraph(1, n, adjList);

    return 0;
}


