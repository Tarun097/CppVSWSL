#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>

using namespace std;

/*
              (5)              (5)
        0-------------->1--------------->2
         \             / \              /
      (2) \       (2) /   \ (1)        / (1)
           \         /     \          /
            \-->3-->/       \-->4--->/


    src = 0, dest = 2

*/

int main(int argc, char const *argv[])
{
    vector<vector<pair<int,int>>> adjList = {
                                                {{1,5},{3,2}},
                                                {{2,5},{4,1}},
                                                {},
                                                {{1,2}},
                                                {{2,1}}
                                            };

    int n = adjList.size();
    int src = 0, dest = 2;
    int maxStops = 2;

    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    vector<int> parent(n, -1);

    queue<pair<int, pair<int,int>>> q;
    q.push({0,{src,0}}); //stops, node, distance

    while (!q.empty())
    {
        int node = q.front().second.first;
        int dis = q.front().second.second;
        int stops = q.front().first;

        q.pop();

        if(stops > maxStops) continue;

        for(auto i : adjList[node]){
            int adjNode = i.first;
            int edgeWt = i.second;

            if(dis + edgeWt < distance[adjNode] && stops <= maxStops){
                distance[adjNode] = dis + edgeWt;
                q.push({stops + 1, {adjNode, distance[adjNode]}});
            }
        }
    }
    
    for(auto i : distance){
        cout << i << " ";
    }
    cout << endl;

    if(distance[dest] == INT_MAX) {
        cout << "No path found within " << maxStops << " stops." << endl;
        return 0;
    }

    return 0;
}
