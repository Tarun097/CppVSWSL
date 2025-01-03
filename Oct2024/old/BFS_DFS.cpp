#include<iostream>
#include<vector>
#include<queue>
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

void BFS(int startingNode , int size , vector<vector<int>> adjList){

    int visited[size] = {0};
    queue<int> q;
    cout << "BFS : " << " ";
    q.push(startingNode);
    visited[startingNode] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for(auto k : adjList[curr]){
            if(!visited[k]){
                q.push(k);
                visited[k] = 1;
            }
        }
    }

    cout << endl;

}

void DFS(int startingNode , int size , vector<vector<int>> adjList){

    int visited[size] = {0};
    stack<int> s;

    s.push(startingNode);

    cout << "DFS : ";

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        visited[curr] = 1;

        cout << curr << " ";

        for(auto k : adjList[curr]){
            if(!visited[k]){
                s.push(k);
                visited[k]= 1;
            }
        }
    }

    cout << endl;

}

void DfsUsingRecursion(int startingNode , vector<vector<int>> adjList, int visited[]){

    if(!visited[startingNode]){

        cout << startingNode << " ";
        visited[startingNode] = 1;
        
        for(auto k : adjList[startingNode]){

            if(!visited[k]){
                DfsUsingRecursion(k, adjList, visited);
            }

        }
    }
}

int main(int argc, char const *argv[])
{
    // vector<int> adjList[] = { {},
    //                           {2,3},
    //                           {1,5},
    //                           {1,4,6},
    //                           {3},
    //                           {2,7},
    //                           {3,7},
    //                           {5,6},
    //                         }; 

    vector<vector<int>> adjList = { {},
                              {2,3},
                              {1,6},
                              {1,4},
                              {3,5},
                              {4},
                              {2}
                            };

    int n = adjList.size();

    cout << "adjacency list\n";

    for(int i =1; i < n; i++){
        cout << i << " : ";
        for(auto j : adjList[i]){
            cout << j << ", ";
        }
        cout << endl;
    }

    int visited[n+1] = {0};

    cout << "\nDFS using recursion\n";
    DfsUsingRecursion(1, adjList, visited);

    cout << "\nDFS using stack\n";
    DFS(1, n, adjList);

    return 0;
}