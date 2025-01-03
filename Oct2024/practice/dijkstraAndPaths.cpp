#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

/*
        (4)        /----3----\ 
     0-----\  (3) /           \ (2)
     |      \    /    (6)      \
(4)  |       2------------------5
     |      /    \             /
     1-----/  (1) \           / (3)
        (2)        \----4----/ 

*/

void printPath(int node, vector<int>& parent){

    vector<int> path;

    while (parent[node]!= node)
    {
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(node);

    std::reverse(path.begin(), path.end());

    for(auto i : path){
        cout << i << " ";
    }
    cout << endl;

}

int main(int argc, char const *argv[])
{
    
    vector<vector<pair<int,int>>> adjList = {
                                                {{1,4},{2,4}},
                                                {{0,4},{2,2}},
                                                {{0,4},{1,2},{3,3},{4,1},{5,6}},
                                                {{2,3},{5,2}},
                                                {{2,1},{5,3}},
                                                {{2,6},{3,2},{4,3}}
                                            };

    int n = adjList.size();

    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1);

    int src = 0;
    distance[src] = 0;
    parent[src] = src;


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

    min_heap.push({0,0}); //distance, node

    while (!min_heap.empty())
    {
        auto it = min_heap.top();
        int node = it.second;
        int dist = it.first;

        min_heap.pop();

        for(auto i : adjList[node]){
            int adjNode = i.first;
            int edgeWt = i.second;

            if(dist+edgeWt < distance[adjNode]){
                distance[adjNode] = dist+edgeWt;
                min_heap.push({distance[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }

    }

    for(int i=0; i<n; i++){
        cout << "To reach : " << i << " distance of " << distance[i] << " is required." << endl;

        printPath(i, parent);
    }

    return 0;
}
