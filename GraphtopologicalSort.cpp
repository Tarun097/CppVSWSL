#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
    // Only possible in DAG

    5 --> 0 <-------- 4
    |                 |
    |-->2--->3--->1<--|

*/

void dfs(int src, vector<vector<int>>& adjList, vector<int>& visited, stack<int>& s){
    visited[src] = 1;

    for(auto neighbour : adjList[src]){
        if(!visited[neighbour]){
            dfs(neighbour, adjList, visited, s);
        }
    }
    
    s.push(src);
}

int main(int argc, char const *argv[])
{

    vector<vector<int>> adjList = {
                                    {},
                                    {},
                                    {3},
                                    {1},
                                    {0,1},
                                    {0,2},
                                  };
    int n = adjList.size();

    vector<int> visited(n,0);
    stack<int> s;

    for(int i = 0; i<=n;i++){
        if(!visited[i]){
            dfs(i, adjList, visited, s);
        }
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}
