#include<iostream>

using namespace std;

void printName(int count){
    
    if(count==0) return;

    cout << "Tarun" << endl;
    printName(--count);
}


void printUptoN(int i, int n){
    if(i>n) return;

    cout << i << " ";

    printUptoN(i+1, n);
}

void printFromNTo1(int i){
    if(i==0) return;

    cout << i << " ";

    printFromNTo1(i-1);
}

void printFromNto1UsingBacktrack(int i, int n){
    if(i>n) return;

    printFromNto1UsingBacktrack(i+1, n);
    cout << i << " ";
}

int main(int argc, char const* argv[]){

    printName(5); cout << endl;

    printUptoN(1,10); cout << endl;

    printFromNTo1(10); cout << endl;

    printFromNto1UsingBacktrack(1, 5);

    return 0;
}