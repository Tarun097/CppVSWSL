#include<iostream>

using namespace std;

int count = 0;

void print(){
    if(count==4) return;
    cout << count++ << " ";
    print();
}


int main(int argc, char const *argv[])
{
    print();
    return 0;
}
