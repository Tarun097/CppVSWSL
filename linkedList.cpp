#include<iostream>
#include<vector>

using namespace std;

class Node{

    public:

        int data;
        Node* next;

        Node(int value){
            data = value;
            next = nullptr;
        }

        Node(int value, Node* ptr){
            data = value;
            next = ptr;
        }
};

Node* push_back(Node* head, int value){
    Node* p = new Node(value);

    // new list
    if(head == nullptr){
        head = p;
        return head;
    }
    // existing list
    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next =  p;

    return head;
}

Node* push_front(Node* head, int value){

    Node* p = new Node(value);

    //new list
    if(head == nullptr){
        head = p;
        return head;
    }

    p->next = head;

    return p;  
}

void printList(Node* head){

    while(head!=nullptr){
        cout << head->data << " ";
        head = head->next;
    }

    cout<< endl;
}

Node* deleteNode(Node* head, int value){

    //list is empty
    if(head==nullptr)
        return nullptr;

    //if head node needs deletion
    if(head->data == value){
        Node* temp = head;
        head = head-> next;
        delete temp;
        return head;
    }

    
    Node* prev = head;
    Node* curr = head->next;

    while (curr != nullptr)
    {
        if(curr->data == value){
            Node* temp = curr;
            prev->next = curr->next;
            delete temp;
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    return head;
}

bool search(Node* head, int value){

    while(head!=nullptr){
        if(head->data == value)
            return true;

        head = head->next;
    }

    return false;
}

Node* delete_front(Node* head){

    if(head==nullptr)
        return nullptr;

    Node* temp = head;
    head=head->next;

    delete temp;
    return head;
}

Node* delete_back(Node* head) {

    if(head == nullptr)
        return nullptr;

    if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (curr->next != nullptr)
    {
        prev = curr;
        curr=curr->next;
    }

    prev->next = nullptr;

    delete curr;
    
    return head;
}

int main(int argc, char const *argv[])
{   
    Node* head = nullptr;

    head = push_back(head,4);
    head = push_back(head,5);
    head = push_back(head,6);
    head = push_back(head,7);

    printList(head);

    head = push_back(head,8);
    head = push_back(head,9);
    head = push_back(head,10);

    printList(head);

    cout << std::boolalpha << search(head, 7) << endl;
    cout << search(head, 17) << endl;

    cout << std::noboolalpha;

    head = push_front(head,3);
    head = push_front(head,2);
    head = push_front(head,1);

    printList(head);

    head = deleteNode(head, 1);
    head = deleteNode(head, 3);
    head = deleteNode(head, 5);
    head = deleteNode(head, 7);
    head = deleteNode(head, 9);
    
    printList(head);

    head = delete_front(head);
    printList(head);

    head = delete_back(head);
    printList(head);

    return 0;
}
