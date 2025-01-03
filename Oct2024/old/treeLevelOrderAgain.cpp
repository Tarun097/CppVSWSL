#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

/*      1
      /  \
    2      3
   / \    / \
  4   5   6   7


*/

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

int treeHeight(Node* node){
    if(node==nullptr) return 0;

    int lh = treeHeight(node->left);
    int rh = treeHeight(node->right);

    return 1 + max(lh,rh);
}


int height(Node* node){
    if(node == nullptr) return 0;

    int lh = height(node->left);
    if(lh == -1) return -1;

    int rh = height(node->right);
    if(rh == -1) return -1;

    if(abs(lh-rh)>1) return -1;

    return 1+max(lh,rh);
}

bool isBalanced(Node* node){
    if(height(node) == -1) return false;
    else return true;
}

int treeHeight(Node* node, int& maxi){
    if(node==nullptr) return 0;

    int lh = treeHeight(node->left, maxi);
    int rh = treeHeight(node->right, maxi);

    maxi = max(maxi, lh+rh);

    return 1 + max(lh,rh);
}

int diameterOfTree(Node* node){
    int max = 0;
    treeHeight(node, max);
    return max;
}

int main(){

    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "height of tree is : " << treeHeight(root) << endl;

    cout << "is tree balanced : " << std::boolalpha << isBalanced(root) << endl;

    cout << "tree diameter is : " << diameterOfTree(root) << endl;

    queue<Node*> q;
    q.push(root);
    vector<vector<int>> bfs;

    while (!q.empty())
    {
        int size = q.size();

        vector<int> level;

        for(int i=0;i<size;i++){

            Node* currNode = q.front();
            q.pop();
            level.push_back(currNode->data);

            if(currNode->left!=nullptr) q.push(currNode->left);
            if(currNode->right!=nullptr) q.push(currNode->right);
        }

        bfs.push_back(level);
    }


    for(auto level : bfs ){
        for(auto element : level){
            cout << element << " ";
        }
        cout << endl;
    }
    



    return 0;
}
