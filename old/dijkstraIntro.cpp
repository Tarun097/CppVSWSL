#include<iostream>
#include<queue>
#include<climits>

using namespace std;

/*
        (4)        /----3----\ 
     0-----\  (3) /           \ (2)
     |      \    /             \
(4)  |       2------------------5
     |      /    \             /
     1-----/  (1) \           / (3)
        (2)        \----4----/ 

*/

int main(int argc, char const *argv[])
{
    vector<vector<pair<int,int>>> adjList = {
                                                {{1,4}, {2,4}},
                                                {{0,4}, {2,2}},
                                                {{0,4},{1,2}, {3,3}, {4,1},{5,6}},
                                                {{2,3},{5,2}},
                                                {{2,1},{5,3}},
                                                {{2,6},{3,2},{4,3}}
                                            };

    int n = adjList.size();

    vector<int> dist(n,INT_MAX);
    int src = 0;
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> min_heap;
    min_heap.push({0,0}); // {distance, node}

    while (!min_heap.empty())
    {
        int node = min_heap.top().second;
        int distance = min_heap.top().first;
        min_heap.pop();

        for(auto neighbour : adjList[node]){
            
            int neighbourNode = neighbour.first; // remember that adjList stores neighbour first, wt second
            int edgeWt = neighbour.second;

            if(distance + edgeWt < dist[neighbourNode]){
                dist[neighbourNode] =  distance + edgeWt;
                min_heap.push({dist[neighbourNode], neighbourNode});
            }
        }
    }
    
    for(auto i : dist){
        cout << i << " ";
    }

    return 0;
}
