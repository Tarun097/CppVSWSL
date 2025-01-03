#include<iostream>
#include<set>
#include<vector>
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

    int n = adjList.size();
    int src = 0;

    vector<int> distance(n,INT_MAX);
    distance[src] = 0;

    set<pair<int,int>> myset;
    myset.insert({0,0}); //distance, node


    while(!myset.empty()){
        auto i = *(myset.begin());
        int node = i.second;
        int dis = i.first;
        myset.erase(i);

        for(auto k : adjList[node]){
            int adjNode = k.first;
            int edgeWt = k.second;

            if(edgeWt+dis < distance[adjNode]){

                if(distance[adjNode] != INT_MAX) //Erase any existing distance if travelled only
                    myset.erase({distance[adjNode], adjNode});

                distance[adjNode] = edgeWt+dis;
                myset.insert({distance[adjNode], adjNode});
            }
        }
    }

    for(auto i: distance){
        cout << i << " ";
    }

    return 0;
}
