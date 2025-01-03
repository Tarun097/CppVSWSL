#include<iostream>
#include<queue>

using namespace std;

class Node{
    public :
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
      /   \
     2     3
    / \   / \
   4   5 6   7


*/

vector<vector<int>> levelOrderTraversal(Node* root){
    queue<Node*> q;
    vector<vector<int>> matrix;

    q.push(root);

    while (!q.empty())
    {
        int queue_size = q.size();
        vector<int> level;

        for(int i=0; i<queue_size; i++){
            Node* curr = q.front();
            q.pop();

            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);

            level.push_back(curr->data);
        }

        matrix.push_back(level);
    }

    return matrix;
}

int main(int argc, char const *argv[])
{
    
    Node* root = new Node(1);
    //left sub-tree
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    //right sub tree
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


    auto ans = levelOrderTraversal(root);

    for(auto row: ans){
        for(auto element : row){
            cout << element << " ";
        }
        cout <<endl;
    }

    return 0;
}
