#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


/*

        1
      /   \
     2     3
    / \   / \
   4   5 6   7

   4 5 2 6 7 3 1

*/

template<typename T>
class Node{
    public:
    T data;
    Node* left;
    Node* right;

    Node(T value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void PreOrderTraversal(Node<int>* root){
    //Root Left Right
    stack<Node<int>*> s;

    s.push(root);

    while (!s.empty())
    {
        Node<int>* curr = s.top();
        cout << curr->data << " "; // read root
        s.pop();
        if(curr->right != nullptr) s.push(curr->right); //push right first, left should be on top to be read first
        if(curr->left != nullptr) s.push(curr->left);
    }
}

vector<int> InOrderTraversal(Node<int>* root){
    stack<Node<int>*> s;

    Node<int>* node = root;

    vector<int> inorder;

    while (true)
    {
        if(node!=nullptr){
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty()) break;
            node = s.top();
            s.pop();
            inorder.push_back(node->data);
            node= node->right;
        }
    }

    return inorder;
}

vector<int> PostOrderTraversal(Node<int>* root){
    
    vector<int> postOrder;

    if(root == nullptr) return postOrder;

    stack<Node<int>*> s1;

    Node<int>* node = root;
    s1.push(root);

    while (!s1.empty())
    {
        node = s1.top();
        postOrder.push_back(node->data);
        s1.pop();

        if(node->left !=nullptr){
            s1.push(node->left);
        }
        
        if(node->right !=nullptr){
             s1.push(node->right);
        }
    }

    std::reverse(postOrder.begin(), postOrder.end());
    return postOrder;
}


int main(int argc, char const *argv[])
{
    Node<int>* root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->left->left = new Node<int>(4);
    root->left->right = new Node<int>(5);

    root->right = new Node<int>(3);
    root->right->left = new Node<int>(6);
    root->right->right = new Node<int>(7);

    // cout << "\nPreOrder\n";
    // PreOrderTraversal(root);

    cout << "\nPostOrder\n";
    auto ans = PostOrderTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    // cout << "\nInOrder\n";
    // ans = InOrderTraversal(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    

    return 0;
}
