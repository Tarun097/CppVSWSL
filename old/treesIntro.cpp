#include<iostream>
#include<vector>

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
    / \
   2   3
    \
     4
*/

void inOrderTraversal(Node* root){
    // Left Root Right
    if(root==nullptr)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void PreOrderTraversal(Node* root){
    // Root Left Right
    if(root==nullptr)
        return;
    
    cout << root->data << " ";

    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root){
    // Left Right Root
    if(root==nullptr)
        return;
    
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

int main(int argc, char const *argv[])
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(3);

    cout << "InOrderTraversal" << endl;
    inOrderTraversal(root);

    cout << "\nPreOrderTraversal" << endl;
    PreOrderTraversal(root);

    cout << "\nPostOrderTraversal" << endl;
    PostOrderTraversal(root);

    cout << endl;

    return 0;
}
