#include<iostream>
#include<vector>
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
              \
               8

*/

//returns height of tree only when it is balanced
int heightOfTree(Node* root){

    if(root==nullptr) return 0;

    int lh = heightOfTree(root->left);
    if(lh==-1) return -1;

    int rh = heightOfTree(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;

    return max(lh, rh) + 1;
}

bool isBalancedTree(Node* root){

    // if(root == nullptr) return true;

    // int lh = heightOfTree(root->left);
    // int rh = heightOfTree(root->right);

    // if(abs(lh-rh) > 1) 
    //     return false;

    // //check if each node is balanced or not
    // if(!isBalancedTree(root->left) || !isBalancedTree(root->right)) return false;

    // return true;

    return heightOfTree(root) != -1;

}

int nodeCount(Node* root){
    
    if(root==nullptr) return 0;

    int leftCOunt = nodeCount(root->left);
    int rightCount = nodeCount(root->right);

    return leftCOunt + rightCount + 1;
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
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);

    cout << "height of tree : " <<  heightOfTree(root) << endl; 

    cout << "is tree balanced : " << std::boolalpha << isBalancedTree(root) << endl;

    cout << "number of nodes : " << nodeCount(root) << endl;

    return 0;
}
