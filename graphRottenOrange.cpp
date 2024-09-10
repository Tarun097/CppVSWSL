#include<iostream>
#include<vector>

using namespace std;

/*
                 row-1, col
    row, col-1,  row, col    , row, col+1
                 row+1, col
*/


int main(int argc, char const *argv[])
{
    int drow[] = { 0, 0, -1, +1};
    int dcol[] = {-1, 1,  0,  0};

    vector<vector<int>> matrix = {   
                                    {1,0,0},
                                    {0,1,0},
                                    {0,0,1}
                                 };

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> copyMatrix(rows, vector<int>(cols, 0));

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j]==1){
                
                //find neighbours
                for(int k=0; k<4; k++){
                    if(i+drow[k]>=0 && i+drow[k]<rows && j+dcol[k]>=0 && j+dcol[k]<cols){
                        copyMatrix[i+drow[k]][j+dcol[k]]++;
                        copyMatrix[i][j] = 1;
                    }
                }
            }
        }
        cout << endl;
    }

    //print matrix
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << copyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
