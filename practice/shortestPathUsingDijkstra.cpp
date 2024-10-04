#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

/*
    //remember each parent of node (where this node is reachable in shortest dist)

              (2)         (5)
        1--------------2-------5
        |               \     /
    (1) |            (4) \   / (1)
        |                 \ /
        4------------------3
                (3)

*/


int main(int argc, char const *argv[])
{
    
    vector<vector<pair<int,int>>> adjList = {
                                                {},
                                                {{2,2},{4,1}},
                                                {{1,2},{3,4},{5,5}},
                                                {{2,4},{4,3},{5,1}},
                                                {{1,1}, {3,3}},
                                                {{2,5}, {3,1}}
                                            }; 
    
    int n = adjList.size(); //5
    int src = 1;
    int dest = 5;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

    vector<int> distance(n+1, INT_MAX);
    distance[src] = 0;

    vector<int> parent(n+1,0);

    for(int i=1; i<n+1; i++){
        parent[i] = i;
    }

    min_heap.push({0,1}); //dist, node

    while (!min_heap.empty())
    {
        int dis = min_heap.top().first;
        int node = min_heap.top().second;
        min_heap.pop();

        for(auto i : adjList[node]){
            int adjNode = i.first;
            int edgeWt = i.second;

            if(dis+edgeWt < distance[adjNode]){
                distance[adjNode] = dis+edgeWt;
                min_heap.push({distance[adjNode], adjNode});

                parent[adjNode] = node;
            }
        }
    }

    vector<int> path;
    int node = dest;

    while(parent[node]!=node){
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(src);


    std::reverse(path.begin(), path.end());


    for(auto i: path){
        cout << i <<  " ";
    }
    
    return 0;
}
