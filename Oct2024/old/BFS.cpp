#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

void DFS(int n, std::vector<int> graph[])
{
    cout << "\nDFS traversal\n";

    int visited[n + 1] = {0};

    stack<int> s;
    s.push(1);

    while (!s.empty())
    {
        int i = s.top();
        s.pop();
        visited[i] = 1;
        cout << i << " ";

        for (auto k : graph[i])
        {
            if (!visited[k])
                s.push(k);
        }
    }
}

void BFS(int n, std::vector<int> graph[])
{
    cout << "\nBFS traversal\n";
    int visited[n + 1] = {0};

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        visited[i] = 1;
        cout << i << " ";

        for (auto k : graph[i])
        {
            if (!visited[k])
                q.push(k);
        }
    }
}

int main(int argc, char const *argv[])
{
    
    /*
    
    1----2
    |
    |
    3---5
    |
    4
    |
    6

    nodes = {1,2,3,4,5,6}
    edges = {(1,2),(1,3),(3,4), (3,5), (4,6)}

    1 3 2 4 5

    */

    int n = 6;
    int m = 5;

    vector<int> graph[n+1] = { {}, {2,3}, {1}, {4,5}, {3,6}, {3}, {4}};


    for(int i=0; i< n; i++){
        cout << i << " : ";
        for(auto j : graph[i]){
            cout << j << ", ";
        }
        cout << endl;
    }

    DFS(n, graph);
    BFS(n, graph);


    return 0;
}


