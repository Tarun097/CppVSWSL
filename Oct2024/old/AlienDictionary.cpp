#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<queue>

using namespace std;

vector<int> toposort(int n, vector<vector<int>>& adjList){
    vector<int> toposort;
    vector<int> indegree(n, 0);

    //create indegree vector
    for(int i=0; i<n; i++){
        for(auto it : adjList[i]){
            indegree[it]++;
        }
    }

    queue<int> q;

    //push nodes with indegree 0 to queue
    for(int i=0; i<n; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        toposort.push_back(curr);

        for(auto it: adjList[curr]){
            indegree[it]--;

            if(indegree[it]==0) q.push(it);
        }
    }

    return toposort;
}


int main(int argc, char const *argv[])
{
    string dict[] = {"bba", "abcd", "abca", "cab", "cad"};
    int n = sizeof(dict)/sizeof(dict[0]);

    /*
    
        b---> a --> c
        |     |
        --> d->
    
    */


    vector<vector<int>> adjList(4); // number of letters

    for(int i=0; i<n-1; i++){
        string s1 = dict[i];
        string s2 = dict[i+1];

        int len = min(s1.length(), s2.length());

        for(int ptr=0; ptr<len; ptr++){
            if(s1[ptr] != s2[ptr]){
                adjList[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                break;
            }
        }
    }

    int x = adjList.size();
    // int y = adjList[0].size();

    // for(int i=0; i<x;i++){
    //     cout << char(i + 'a') << " : " ;
    //     for(auto it : adjList[i]){
    //         cout << char(it+'a') << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> topo = toposort(4, adjList); // number of letters = number of nodes

    for(auto it : topo){
        cout << char(it+'a') << " ";
    }

    return 0;
}
