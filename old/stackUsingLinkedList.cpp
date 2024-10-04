#include<iostream>

using namespace std;

template <typename T>
class Node{

public:
    T data;
    Node* next;

    Node(T value){
        data = value;
        next = nullptr;
    }

    Node(T value, Node* ptr){
        data = value;
        next = ptr;
    }
};

template<typename U>
class Stack {

private:
    Node<U>* head = nullptr;
    int _size = 0;

public:

    Node<U>* push(U value) {
        _size++;

        Node<U>* p = new Node(value);

        //empty stack
        if(head==nullptr){
            head = p;
            return head;
        }
        else{
            Node<U>* curr = head;
            
            while(curr->next!=nullptr)
                curr = curr->next;

            curr->next = p;
        }

        return head;
    }

    U pop(){

        if(_size==0){
            cout<< "Stack is empty" << endl;
            return -1;
        }
        else{
            _size--;

            Node<U>* curr = head;
            Node<U>* prev = nullptr;

            //delete only node
            if(curr->next == nullptr){
                U poppedItem = curr->data;
                delete curr;
                head = nullptr;
                return poppedItem;
            }

            while(curr->next!=nullptr){
                prev = curr;
                curr = curr->next;
            }

            prev->next = nullptr;
            
            U poppedItem = curr->data;
            
            delete curr;
            
            return poppedItem;
        }
    }

    U Top(){

        if(_size==0){
            cout << "Stack is empty" << endl;
            return -1;
        }

        Node<U>* curr = head;

        while(curr->next != nullptr){
            curr = curr->next;
        }

        return curr->data;
    }

    int Size(){
        return _size;
    }

    void print(){

        if(_size==0){
            cout << "stack is empty\n";
            return;
        }

        Node<U>* curr = head;

        while(curr!=nullptr){
            std::cout << curr->data << " ";
            curr = curr->next;
        }

        std::cout << endl;
    }

};


int main(int argc, char const *argv[])
{
    Stack<int> st;

    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);


    st.print();

    std::cout << "stack size is : " << st.Size() << std::endl;

    std::cout << "stack top is : " << st.Top() << std::endl;

    std::cout << "pop : " << st.pop() << endl;
    std::cout << "pop : " << st.pop() << endl;
    std::cout << "pop : " << st.pop() << endl;
    std::cout << "pop : " << st.pop() << endl;
    std::cout << "pop : " << st.pop() << endl;
    std::cout << "pop : " << st.pop() << endl;




    st.print();

    return 0;
}