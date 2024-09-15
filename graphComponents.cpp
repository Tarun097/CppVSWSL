#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*

    1-2   3-4-5

*/


void graphDFS(int src ,int n, vector<int> adjlist[], int visited[]){

    stack<int> s;
    s.push(src);

    while(!s.empty()){

        int curr = s.top();

        cout << curr << " ";

        s.pop();

        visited[curr] = 1;
        for(auto i : adjlist[curr]){
            if(!visited[i]){
                s.push(i);
            }
        }

    }

}

int main(int argc, char const *argv[])
{


    vector<int> adjList[] = { {},
                              {2},
                              {1},
                              {4},
                              {3,5},
                              {4}
                            };

    int n = sizeof(adjList)/ sizeof(adjList[0]); //n=6

    int visited[n] = {0}; 

    int count = 0;

    for(int i=1; i< n; i++){
        if(!visited[i]){
            count++;
            graphDFS(i , n, adjList, visited);
        }
    }

    cout << "\nnumber of components : " << count << endl;

    return 0;
}
