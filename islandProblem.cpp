#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;


/*
    -1,-1  -1,0  -1,1

     0,-1   0,0   0,1

     1,-1   1,0   1,1

*/


void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited){
    
    queue<pair<int,int>> q;

    q.push(make_pair(row,col));

    visited[row][col] = 1;

    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        auto curr = q.front();
        int i = curr.first;
        int j = curr.second;

        q.pop();

        vector<int> deltaRow = {-1, -1,  0, 1, 1,  1,  0, -1};
        vector<int> deltaCol = { 0,  1,  1, 1, 0, -1, -1, -1};

        //check neighbours , if not visited put them in queue
        for(int k=0; k<8; k++){

            int neighbourRow = i + deltaRow[k];
            int neighbourCol = j + deltaCol[k];

            if(neighbourRow >= 0 && neighbourRow < n
                && neighbourCol >=0 && neighbourCol < m
                && !visited[neighbourRow][neighbourCol] && grid[neighbourRow][neighbourCol]==1){
                    visited[neighbourRow][neighbourCol]=1;
                    q.push(make_pair(neighbourRow, neighbourCol));
                }
        }

    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = { {0,1,1,0},
                                 {0,1,1,0},
                                 {0,0,1,0},
                                 {0,0,0,0},
                                 {1,1,0,1}
                               };

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m,0)); //visited grid

    int count = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && grid[i][j]==1){
                count++;
                bfs(i,j,grid,visited);
            }
        }
    }

    cout << count << endl;

    return 0;
}
