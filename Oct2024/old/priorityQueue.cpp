#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char const* argv[]){

    priority_queue<int> q; //by default it's max-heap

    q.push(10);
    q.push(2);
    q.push(4);
    q.push(14);

    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }


    cout << endl << "min heap" << endl;

    priority_queue<int, vector<int>, std::greater<int>> min_heap;

    min_heap.push(1);
    min_heap.push(12);
    min_heap.push(10);
    min_heap.push(2);

    while (!min_heap.empty())
    {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }

    return 0;
}