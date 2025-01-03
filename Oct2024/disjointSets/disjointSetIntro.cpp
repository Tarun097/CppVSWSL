#include<iostream>
#include<vector>

using namespace std;

class DisjointSet{

    private:
    
        vector<int> rank, parent, size;

        
    
    public:

        DisjointSet(int noOfNodes){

            rank.resize(noOfNodes+1, 0);  //n+1 if it's 1 based indexing graph
            parent.resize(noOfNodes+1);
            size.resize(noOfNodes+1);

            for(int i=0; i<noOfNodes+1; i++){
                parent[i] = i;
                size[i] = 1;  //initially size of each node is 1
            }
        }

        int findUParent(int node){

            if(node == parent[node])
                return node;
            
            return parent[node] = findUParent(parent[node]);
            //path compression 
            //in case of rank, path compression distorts the rank, so rank cannot be used as height
        }

        void unionByRank(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);

            if(ulp_u == ulp_v) return;  // already connected

            if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;  //attach smaller to larger always
            }
            else if (rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v; //attach smaller to larger always
            }else{
                //if height increases , rank will increase
                //in above conditions, height won't increase as we are always adding smaller to larger
                parent[ulp_v] = ulp_u; //attach v with u  i.e v--->u , or opposite way
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);

            if(ulp_u == ulp_v) return;  // if ultimate parents are same then already connected

            if(size[ulp_u] > size[ulp_v]){
                //attach smaller size to larger
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }else{
                //attach smaller size to larger
                //equal case we can attach anywhere, so else part will take care
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }

        }

};

int main(int argc, char const *argv[])
{
    DisjointSet ds(7);

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    //check if 3 and 7 belong to same component of not ?

    if(ds.findUParent(3) == ds.findUParent(7))
        cout << "3 and 7 belong to same component" << endl;
    else    
        cout << "3 and 7 does not belong to same component"<< endl;

    ds.unionBySize(3,7);

    if(ds.findUParent(3) == ds.findUParent(7))
        cout << "3 and 7 belong to same component"<< endl;
    else    
        cout << "3 and 7 does not belong to same component"<< endl;

    return 0;
}
