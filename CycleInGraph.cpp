#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<stack>

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
                cout << "\ncycle detected : " << adjacentNode << " - " << parent << endl ;
                return;
            }
        }  

    }

    cout << "No cycle" << endl;  
}

void detectCycleInGraphUsingDFS(int source , int n, vector<vector<int>> adjList){
    int visited[n+1] = {0};
    
    stack<pair<int,int>> s;

    s.push(make_pair(source,-1));
    visited[source] = 1;

    cout << "DFS : ";

    while (!s.empty())
    {
        int node = s.top().first;
        int parent = s.top().second;
        s.pop();

        cout << node  << ", ";

        for(auto adjacentNode : adjList[node]){
            if(!visited[adjacentNode]){
                visited[adjacentNode]=1;
                s.push(make_pair(adjacentNode,node));
            }else if(adjacentNode != parent) //if already visted , and not parent, then it has cycle
            {
                cout << "\ncycle detected : " << adjacentNode << " - " << parent << endl ;
                return;
            }
        }  

    }

    cout << "No cycle" << endl;  
}

int main(int argc, char const *argv[])
{
    // vector<vector<int>> adjList = {
    //     {},
    //     {2,3},
    //     {1,5},
    //     {1,4,6},
    //     {3},
    //     {2,7},
    //     {3,7},
    //     {5,6}
    // };

        vector<vector<int>> adjList = { {},
                              {2,3},
                              {1,6},
                              {1,4},
                              {3,5},
                              {4},
                              {2}
                            };

    int n = adjList.size();

    for(int i=1; i<n; i++){
        cout << i << " : ";
        for(auto k : adjList[i]){
            cout << k << ", ";
        }
        cout << endl;
    }

    detectCycleInGraphUsingDFS(1, n, adjList);

    return 0;
}


