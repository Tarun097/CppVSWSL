#include<iostream>
#include<vector>
#include<queue>
#include<climits>

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

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
    
    int n = adjList.size();
    vector<int> distance(n,INT_MAX);

    int src = 0;
    distance[src] = 0;

    min_heap.push({0,0}); //distance,node

    while (!min_heap.empty())
    {
        int dis = min_heap.top().first;
        int node = min_heap.top().second;
        min_heap.pop();

        for(auto i : adjList[node]){
            int adjNode = i.first;
            int edgeWt = i.second;

            if(dis + edgeWt < distance[adjNode]){
                distance[adjNode] = dis+edgeWt;
                min_heap.push({distance[adjNode],adjNode});
            }
        }
    }

    for(auto i : distance){
        cout << i << " ";
    }

    return 0;
}
