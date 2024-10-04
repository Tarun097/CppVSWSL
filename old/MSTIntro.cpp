#include<iostream>
#include<vector>
#include<queue>

//prim's algo

using namespace std;

/*


     find minimum spanning tree
     - spanning tree : N nodes, N-1 edges and all nodes are reachable
       If edges are selected in such a way that it gives minimum sum, it is MST

       (2)    (3)
     0------1------2
     |    / |     /
 (6) |   /  |(5) /
     |  /   |   /
     | /(8) |  / (7) 
     |/     | /
     3      4

     use min heap, 
     start from a node, 
     add all the edges into queue
     take the min, if not visited add to mst 


*/

int main(int argc, char const *argv[])
{

    vector<vector<pair<int,int>>> adjList = {
                                    {{1,2},{3,6}},
                                    {{0,2},{2,3},{3,8},{4,5}},
                                    {{1,3},{4,7}},
                                    {{0,6},{1,8}},
                                    {{1,5},{2,7}},
                                  };

    int n = adjList.size();

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> min_heap; //wt, node, parent

    vector<pair<int,int>> mstList;
    vector<int> vistied(n,0);

    int src = 0;
    min_heap.push({0,{src, -1}});  //edgeWt, node, parent

    int sum = 0;

    while (!min_heap.empty())
    {
      //takes the edge with min wt
      auto it = min_heap.top();
      min_heap.pop();


      int wt = it.first;
      int node = it.second.first;
      int parent = it.second.second;

      //already visited and part of mst
      if(vistied[node]) continue;

      //don't add if parent is -1 ad it is not an edge
      if(parent != -1){
        mstList.push_back({parent, node});
        sum+=wt;
      }

      vistied[node] = 1;

      for(auto i : adjList[node]){
        int adjNode = i.first;
        int edgeWt = i.second;
        
        //add the neighbouring edges which are not visited
        if(!vistied[adjNode]){
          min_heap.push({edgeWt,{adjNode,node}});
        }
      }

    }

    for(auto edge : mstList){
      cout << "{" << edge.first << "," << edge.second << "}" << endl;
    }

    cout << "sum is : " << sum << endl;
    

    return 0;
}
