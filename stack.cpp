#include<iostream>

using namespace std;

class Stack{

private:
    int arr[10];
    int capacity = 10;
    int _top = -1;

public:
    Stack(){}

    int size(){
        return _top+1;
    }

    int top(){
        return arr[_top];
    }

    void pop(){

        if(_top==-1){
            std::cout << "underflow\n";
        }
        else{
            _top--;
        }
    }

    void push(int x){
        
        if(_top == capacity-1){
            std::cout << "overflow\n";
        }
        else{
            arr[++_top] = x;
        }

    }

    void print(){

        for(int i=0; i<=_top; i++)
            cout << arr[i] << " ";
        
        cout << endl; 

    }

};

int main(int argc, char const *argv[])
{
    Stack st;

    st.push(1);
    st.push(2);

    st.print();

    st.pop();

    cout << "top : " << st.top() << endl;
    st.pop();

    st.pop(); //underflow

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    st.push(11); //overflow


    st.print();


    return 0;
}

