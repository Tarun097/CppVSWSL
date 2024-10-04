#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> findToposort(int n, vector<vector<int>>& adjList){

    vector<int> indegree(n, 0);

    for(int i=1;i<n; i++){
        for(auto it: adjList[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    vector<int> toposort;

    for(int i=1;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        toposort.push_back(node);

        for(auto neighbour : adjList[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0) q.push(neighbour);
        }

    }
    
    return toposort;
}


/*
    1-->2------->3--->4
        |-<-5-<--|
*/

int main(int argc, char* const argv[]){

    vector<vector<int>> adjList = {{}, {2}, {3}, {4,5}, {}, {2}};
    int n = adjList.size();
    auto topo = findToposort(n, adjList);

    for(auto it : topo){
        cout << it << " ";
    }

    //As the number of elements in toposort are not equal to number of vertices, there is a cycle
    //Only DAGs can have toposort
    //so we try to find toposort for directed cyclic graph (which is not possible)

    return 0;
}