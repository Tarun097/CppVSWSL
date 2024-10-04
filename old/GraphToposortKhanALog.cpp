#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
                |----->5
    1---->2---->3           
                |----->4<------6
                       |
                       |---<----7

    maintain indegree array
    do BFS, put nodes with indegree 0 in queue
    take them out, reduce indegree of their adjacent nodes
    check after reducing, if any adjacent node has indegree 0, push it into queue

    toposort only for DAG
    it will have atleast one node with indegree 0

*/


int main(int argc, char const *argv[])
{
    vector<vector<int>> adjList = {
                                    {},
                                    {2},
                                    {3},
                                    {4,5},
                                    {},
                                    {},
                                    {4},
                                    {4}
                                  };

    
    int n = adjList.size();

    vector<int> indegree(n,0);

    for(int i=1; i<n;i++){
        for(auto neighbour : adjList[i]){
            indegree[neighbour]++;
        }
    }

    vector<int> toposort;
    

    queue<int> q;
    for(int i=1;i<n;i++){  // n = 8
        if(indegree[i]==0) q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        toposort.push_back(node);

        for(auto it : adjList[node]){
            indegree[it]--;
            if(indegree[it]==0)  q.push(it);
        }
    }

    for(auto it : toposort){
        cout << it << " ";
    }

    return 0;
}
