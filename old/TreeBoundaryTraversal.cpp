#include<iostream>
#include<vector>

using namespace std;


/*
            1
          /   \
         2     5
        /       \
       3         6
        \        / 
         4      7




*/

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

bool isLeaf(Node* node){
    return !node->left && !node->right;
}

void getLeftBoundaryTraversal(Node* root, vector<int>& res){
    Node* curr = root->left;

    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);

        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }

}

void getRightBoundaryTraversal(Node* root, vector<int>& res){
    Node* curr = root->right;
    vector<int> rightBoundary;

    while(curr){
        if(!isLeaf(curr)) rightBoundary.push_back(curr->data);

        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for(int i=rightBoundary.size()-1; i>=0; i--){
        res.push_back(rightBoundary[i]);
    }
}

void getLeafNodes(Node* root, vector<int>& res){

    //In order traversal Left Root Right
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    } 

    if(root->left) getLeafNodes(root->left, res);
    if(root->right) getLeafNodes(root->right, res);
}

void boundaryTraversal(Node* root, vector<int>& res){
    if(!isLeaf(root))
        res.push_back(root->data);

    getLeftBoundaryTraversal(root, res);
    getLeafNodes(root, res);
    getRightBoundaryTraversal(root, res);
}

int main(int argc, char const* argv[]){

    Node* root =  new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right =  new Node(4);

    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);


    vector<int> res;

    boundaryTraversal(root, res);

    for(auto i : res){
        cout << i << " ";
    }


    return 0;
}