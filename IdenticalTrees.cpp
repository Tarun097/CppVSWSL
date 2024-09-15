#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
    }
};


/*
        1
       / \
      2   3


*/

bool compareTree(Node* root1, Node* root2){
    if(root1 == nullptr || root2== nullptr)
        return root1 == root2;

    return root1->data == root2->data && 
        compareTree(root1->left, root2->left) &&
        compareTree(root1->right, root2->right);
}

int main(int argc, char const* argv[]){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    cout << std::boolalpha << compareTree(root, root1) << endl;

    return 0;

}