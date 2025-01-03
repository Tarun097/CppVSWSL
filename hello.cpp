#include<iostream>
#include<vector>
#include<array>

using namespace std;

class Person{
    private:
        string name;
        int age;

    public:

        Person(string name, int age) : name(name), age(age) {}

        void display(){
            cout << "Name: " << name << " Age: " << age << endl;
        }
};

int main(int argc, char const *argv[])
{

    int arr[5]{};

    // vector<int> v = {0};

    // for(auto i : v){
    //     cout << i << " ";
    // }

    for(int i=0; i<5; i++){
        cout<< arr[i] << " ";
    }

    return 0;
}