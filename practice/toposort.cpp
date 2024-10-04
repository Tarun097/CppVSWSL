#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/*

    5 --> 0 <-------- 4
    |                 |
    |-->2--->3--->1<--|

*/

void toposortUsingKhanAlgo(int n, vector<vector<int>> adjList){

    vector<int> indegree(n,0);

    for(auto neighbourNodes : adjList){
        for(int adjNode : neighbourNodes){
            indegree[adjNode]++;
        }
    }

    queue<int> q;

    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();

        for(auto adjNode : adjList[node]){
            indegree[adjNode]--;
            if(indegree[adjNode]==0) q.push(adjNode);
        }
    }

}


void topsort(int src, vector<vector<int>> adjList, stack<int>& s, vector<int>& visited){
    visited[src] = 1;

    for(auto i: adjList[src]){
        if(!visited[i]) topsort(i, adjList, s, visited);
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
                            {0,2}
                          };

    int n = adjList.size();

    // stack<int> s;
    // vector<int> visited(n,0);

    // for(int i=0; i<n; i++){
    //     if(!visited[i]) topsort(i, adjList, s, visited);
    // }

    // while (!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    toposortUsingKhanAlgo(n, adjList);

    return 0;
}
