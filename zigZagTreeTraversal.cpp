#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


/*
         1
       /  \
      2    3
     / \  / \
    4   5 6  7

*/


vector<vector<int>> zigZagTraversal(Node* root){

    vector<vector<int>> traversal;

    if(root==nullptr) return traversal;

    bool leftToRight = true;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);

        for(int i=0; i<size; i++){
            Node* curr = q.front();
            q.pop();

            int k = leftToRight ? i : size-1-i;

            row[k] = curr->data;

            if(curr->left) q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }

        leftToRight = !leftToRight;

        traversal.push_back(row);
    }

    return traversal;

}

int main(int argc, char const* argv[]){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    auto traversal = zigZagTraversal(root);

    for(auto row : traversal){
        for(auto i : row){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}