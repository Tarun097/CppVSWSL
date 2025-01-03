#include<iostream>
#include<set>

using namespace std;

int main(int argc, char const *argv[])
{
    
    set<int> s; //stores elements in increasing order

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    while (!s.empty())
    {
        auto node  = *(s.begin());
        cout << node << " ";
        s.erase(node);
    }
    


    return 0;
}
