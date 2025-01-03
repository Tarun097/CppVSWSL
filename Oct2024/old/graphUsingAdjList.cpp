#include<iostream>
#include<vector>
#include<utility>

using namespace std;

    /*
    
        1 ----------- 2
        |
        |
        3-----4

        nodes = (1,2,3,4)
        edges = {(1,2), (1,3), (3,4)}

        n = 4
        m = 3
    
    */

int main(int argc, char const *argv[])
{
    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> graph[n+1];

    for(int i=0; i<m; i++){ // m edges
        int u,v, w;
        cin >> u >> v  >> w;

        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }


    for(int i=0; i< n+1; i++){
        cout << i << " : ";
        for(auto j : graph[i]){
            cout << "(" << j.first << ", " << j.second << ")" << ", ";
        }
        cout << endl;
    }


    return 0;
}
