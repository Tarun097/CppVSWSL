#include<iostream>
#include<set>
#include<climits>
#include<vector>

using namespace std;

/*
        (4)        /----3----\ 
     0-----\  (3) /           \ (2)
     |      \    /   (6)       \
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

    set<pair<int,int>> myset;
    myset.insert({0,0});

    while (!myset.empty())
    {
        auto it = *(myset.begin()); //take the one with shortest distance
        int distance = it.first;
        int node = it.second;
        myset.erase(it);

        for(auto i: adjList[node]){
            int neighbour = i.first;
            int edgeWt = i.second;

            if(distance + edgeWt < dist[neighbour]){

                if(dist[neighbour]!= INT_MAX){ //Optimization - if someone has already reached that node
                    myset.erase({dist[neighbour], neighbour});
                }

                dist[neighbour] = distance+edgeWt;
                myset.insert({dist[neighbour], neighbour});

            }
        }
    }

    for(auto i : dist){
        cout << i << " ";
    }

    return 0;
}
