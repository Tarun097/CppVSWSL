#include<iostream>
#include<vector>
#include<utility>
#include<stack>
#include<climits>
#include<algorithm>

using namespace std;

/*                
                      (1)           (3)
                |----------->2------>----------|
                |                              |
         (2)    |  (3)       (2)       (1)     |
    6---------->4-------->0-------->1--------->3
    |           |
 (3)|           |(1)
    |           |
    |-->--5-->--|

*/

void toposort(int src, vector<vector<pair<int,int>>>& adjList, stack<int>& s, vector<int>& visited){
    visited[src] = 1;

    for(auto it : adjList[src]){
        int v = it.first;
        if(!visited[v])
            toposort(it.first, adjList, s, visited);
    }

    s.push(src);
}

int main(int argc, char const* argv[]){

    int n = 7; //nodes
    int m = 8; // edges

    vector<int> edges[] = {
                            {6,4,2},
                            {6,5,3},
                            {5,4,1},
                            {4,0,3},
                            {4,2,1},
                            {0,1,2},
                            {1,3,1},
                            {2,3,3}
                          };


    vector<vector<pair<int,int>>> adjList(n);

    /*
        [ 
          [{negh ,wt},{negh,wt}]
        ]
    */

    //create adj list
    for(int i=0; i<m; i++){
        
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adjList[u].push_back({v,wt}); //inserting a pair
    }

    //print adj list
    for(int i = 0; i<n; i++){
        cout << i << " : ";
        for(auto edge : adjList[i]){
            cout << "{" << edge.first << "," << edge.second << "}" << ",";
        }
        cout << endl;
    }

    //find topo sort
    stack<int> s;
    vector<int> visited(n,0);

    int src = 6;
    toposort(src, adjList, s, visited); //source node 6

    vector<int> distance(n, INT_MAX);
    distance[src] = 0; //to travel from 6 to 6 is 0 distance

    while(!s.empty()){

        int node  = s.top();
        s.pop();

        for(auto it : adjList[node]){
            int v = it.first;
            int wt = it.second;

            if(distance[node]+ wt < distance[v]){
                distance[v] = distance[node]+ wt;
            }
        }
    }

    for(auto it : distance){
        cout << it << " ";
    }

    return 0;
}