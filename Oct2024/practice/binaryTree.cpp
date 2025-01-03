#include<iostream>
#include<climits>

using namespace std;


struct Node
{
    Node* left;
    Node* right;
    int data;

    Node(int value){
        data=value;
        left=right=nullptr;
    }
};


void InOrder(Node* root){
    if(root==nullptr) return;

    InOrder(root->left);
    cout<< root->data <<" ";
    InOrder(root->right);
}

/*

         10
       /    \
     5       12
    / \        \
   1   7        14

*/

Node* InsertNode(Node* root, int data){
    
    if(root==nullptr)
        root = new Node(data);
    else if(data > root->data) //insert in right subtree
        root->right = InsertNode(root->right, data);
    else if(data <= root->data)
        root->left = InsertNode(root->left, data);

    return root;
}

int getMax(Node* root){

    if(root==nullptr)
        return -1;

    while (root->right!=nullptr)
    {
       root = root->right;
    }

    return root->data;
}

int getMin(Node* root){

    if(root==nullptr)
        return -1;

    while (root->left!=nullptr)
    {
       root = root->left;
    }

    return root->data;
}

bool isTreeBST(Node* root, Node* minNode, Node* maxNode){

    if(root==nullptr)
        return true;

    if((minNode != nullptr && root->data <= minNode->data) ||
        (maxNode != nullptr && root->data > maxNode->data))
        return false;

    return isTreeBST(root->left, minNode, root) && isTreeBST(root->right, root, maxNode);
}


bool isTreeBST(Node* root, int min, int max){

    if(root==nullptr)
        return true;

    if(root->data > max || root->data < min) 
        return false;

    return isTreeBST(root->left, min, root->data) && isTreeBST(root->right, root->data, max);
}


bool search(Node* root, int value){

    if(root==nullptr)
        return false;

    if(root->data==value) 
        return true;
    else if(value > root->data)
        return search(root->right, value);
    else
        return search(root->left, value);

}

Node* searchNode(Node* root, int value){

    while(root!=nullptr && root->data != value){
        root = value > root->data ? root->right : root->left; 
    }

    return root;
}

int main(int argc, char const *argv[])
{
    Node *root = nullptr;
    root = InsertNode(root, 10);
    root = InsertNode(root, 5);
    root = InsertNode(root, 12);
    root = InsertNode(root, 1);
    root = InsertNode(root, 7);
    root = InsertNode(root, 14);

    InOrder(root);

    cout << endl;

    cout << "Max is : " << getMax(root) << endl;
    cout << "Min is : " << getMin(root) << endl;


    cout << std::boolalpha << isTreeBST(root, nullptr, nullptr) << endl;

    cout << std::boolalpha << isTreeBST(root, INT_MIN, INT_MAX) << endl;

    cout << search(root, 14) << endl;

    Node* fiveNode = searchNode(root, 5);

    InOrder(fiveNode);
    
    return 0;
}
