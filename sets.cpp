#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main(int argc, char const* argv[]){

    set<int> s = {1,2,3,4};


    for(auto i : s){
        cout << i << " ";
    }

    s.insert(5);
    s.insert(7);
    s.insert(1); //ignored

    cout << endl;

    for(auto i : s){
        cout << i << " ";
    }

    s.erase(3);

    cout << endl;

    for(auto i : s){
        cout << i << " ";
    }

    set<int, std::greater<int>> s2 = {3,4,5,6,7,8};

    cout << "\ns2 : ";

    for(auto i : s2){
        cout << i << " ";
    }

    vector<int> intersection;

    std::set_intersection(s.begin(), s.end(), s2.begin(), s2.end(), std::back_inserter(intersection));

    cout << endl;

    for(auto i : intersection){
        cout << i << " ";
    }

    cout << endl;

    return 0;
}