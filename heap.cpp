#include<iostream>
#include<vector>

using namespace std;

class MyHeap{

private:
    vector<int> arr;

    void upheap(int index){
        if(index == 0) return;

        int pIndex = parent(index);

        if(arr[pIndex] > arr[index]){
            std::swap(arr[pIndex], arr[index]);
            upheap(pIndex);
        }
    }

    void downheap(int index){
        int min = index;
        int leftIndex = left(index);
        int rightIndex = right(index);

        if(leftIndex < arr.size() && arr[leftIndex] < arr[index]){
            min = leftIndex;
        }

        if(rightIndex < arr.size() && arr[rightIndex] < arr[index]){
            min = rightIndex;
        }

        if(min != index){
            swap(arr[min], arr[index]);
            downheap(min);
        }
    }

    int parent(int index) {
        return (index-1)/2;
    }

    int left(int index){
        return (2 * index + 1);
    }

    int right(int index){
        return (2 * index + 2);
    }


public:

    void insert(int number){
        arr.push_back(number); // add element at the last
        upheap(arr.size()-1); //up heap from last index
    }

    int remove(){

        if(arr.size() == 0){
            throw std::runtime_error("heap is empty");
        }

        int temp = arr[0];

        int lastElement = arr[arr.size()-1];
        arr.pop_back();

        if(!arr.empty()){
            arr[0] = lastElement;
            downheap(0);
        }

        return temp;
    }

    vector<int> heapSort(){
        vector<int> sortedArray;

        while(!arr.empty()){
            sortedArray.push_back(remove());
        }

        return sortedArray;
    }

};

int main(int argc, char const *argv[])
{
    MyHeap heap;

    heap.insert(22);
    heap.insert(20);
    heap.insert(10);
    heap.insert(40);

    cout << heap.remove() << endl;


    auto sortedArray = heap.heapSort();
    
    for(auto i : sortedArray){
        cout << i << " ";
    }

    return 0;
}
