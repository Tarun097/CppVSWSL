#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{

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

    int n,m;

    cin >> n >> m;

    vector<vector<int>> graph(n+1,vector<int>(n+1,0));

    for(int i=0; i<m; i++){ //m edges
        int u, v;
        cin >> u >> v;

        graph[u][v]=1;
        graph[v][u]=1;
    }

    for(int i=0;i<n+1;i++){
        for(int j=0; j<n+1; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
