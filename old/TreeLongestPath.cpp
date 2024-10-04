#include<iostream>
#include<cmath>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data= value;
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
        /     \
       9       8
      /         \
    10          12
    /             \
  11              13

*/

int findHeight(Node* root){

    if(root == nullptr) return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight,rightHeight) + 1;
}

int longestPath = 0;

void findLongestPath(Node* root){

    if(root == nullptr) return;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    longestPath = max(longestPath, leftHeight+rightHeight);

    findLongestPath(root->left);
    findLongestPath(root->right);
}

int findLongestPathOptimized(Node* root){

    if(root == nullptr) return 0;

    int leftHeight = findLongestPathOptimized(root->left);
    int rightHeight = findLongestPathOptimized(root->right);

    longestPath = max(longestPath, leftHeight+rightHeight);

    return max(leftHeight,rightHeight) + 1;
}

int main(int argc, char const *argv[])
{

    Node* root = new Node(1);
    //left sub tree
    root->left = new Node(2);
    root->left->left =  new Node(4);
    root->left->right = new Node(5);

    //right sub tree
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left =  new Node(9);
    root->right->left->left->left = new Node(10);
    root->right->left->left->left->left = new Node(11);

    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(12);
    root->right->right->right->right->right = new Node(13);


    cout << "tree height : " << findHeight(root) <<  endl;

    findLongestPathOptimized(root);

    cout << "longest path : " << longestPath <<  endl;
    
    return 0;
}
