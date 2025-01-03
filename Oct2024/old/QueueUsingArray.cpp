#include<iostream>

using namespace std;

class Queue{

private:
    static const int capacity = 4;
    int arr[capacity] = {0};
    int start = -1, end = -1;
    int currentSize = 0;

public:
    void push(int value){
        
        if(currentSize==capacity){
            cout << "No space" << endl;
            return;
        }
        else if(currentSize==0){
            start = 0, end = 0;
        }
        else{
            end = (end+1) % capacity;
        }

        arr[end] = value;
        currentSize++;
    }

    int size(){
        return currentSize;
    }

    int pop(){

        if(currentSize == 0){
            cout << "Queue is empty" << endl;
            return -999;
        }
        
        int value = arr[start];

        if(currentSize == 1){
            start = -1;
            end = -1;
        }
        else{
            start = (start+1) % capacity;
        }

        currentSize--;
        return value;
    }

    void print(){
        if(currentSize == 0){
            cout << "Queue is empty" << endl;
        }
        else{
            for(int i = start; i<=end; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }


};


int main(int argc, char const *argv[])
{
    Queue q;


    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); // no space

    q.print();

    cout << "size : " << q.size() << endl;

    cout << "poping : " << q.pop() << endl;

    cout << "size : " << q.size() << endl;

    q.print();

    cout << "poping : " << q.pop() << endl;
    cout << "poping : " << q.pop() << endl;
    cout << "poping : " << q.pop() << endl;

    cout << "size : " << q.size() << endl;

    cout << "poping : " << q.pop() << endl;

    cout << "size : " << q.size() << endl;

    q.print();


    return 0;
}
