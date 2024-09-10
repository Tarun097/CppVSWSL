#include<iostream>
using namespace std;

/*

start = -1 , end = -1  size (-1--1) = 0

start = 0 end =0  size (0)

*/

class Queue{
    int arr[10];
    int n = 10;

    int start =-1, end = -1;
    //int currentSize = 0;

public :

    int size(){
        if(start==-1 && end==-1){
            return 0;
        }
        else{
            return end-start+1;
        }
    }

    void push(int value){

        if(start==-1){
            start++;
        }

        arr[++end] = value;
    }

    int pop(){

        // cout <<"start : " << start << endl;
        // cout <<"end : " << end << endl;

        if((end-start) == 0){
            start=-1, end=-1;
            cout << "queue is empty";
            return -1;
        }

        int value = arr[start];
        start++;

        return value;
    }

    int top(){
        return arr[start];
    }

    void print(){

        if(start==-1 && end==-1){
            cout << "Queue is empty" << endl;
            return;
        }

        int i = start;
        while(i<=end){
            cout << arr[i] << " ";
            i++;
        }

        cout << endl;
    }

    void printIndex(){
        cout << "start : " << start <<endl;
        cout << "end : " << end <<endl;
    }

};

int main(int argc, char const *argv[])
{
    Queue q;

    q.print();

    q.push(1);
    q.push(2);
    q.push(3);


    q.print();

    cout << "size is : " << q.size() << endl;


    cout << "top : " << q.top() << endl;
    cout << "poping : " << q.pop() << endl;
    cout << "size is : " << q.size() << endl;
    q.print();

    q.push(4);
    q.push(5);

    q.print();


    q.printIndex();


    cout << "poping : " << q.pop() << endl;
    cout << "poping : " << q.pop() << endl;
    cout << "poping : " << q.pop() << endl;

    q.print();
    q.printIndex();
    cout << "size is : " << q.size() << endl;

    cout << "top : " << q.top() << endl;


    return 0;
}
