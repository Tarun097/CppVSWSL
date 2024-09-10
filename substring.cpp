#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string str = "Hello World - How are you ?";

    string temp;
    for (auto i = str.rbegin(); i != str.rend(); i++)
    {
        temp = temp + *i;
    }

    cout << temp << endl;
    

    string hello = str.substr(0, 5);

    cout << hello << endl;

    string reversedStr(str.rbegin(), str.rend());

    cout << reversedStr << endl;

    auto greeting =  str.substr(str.find("-") + 1);

    cout << greeting << endl;

    std::reverse(str.begin(), str.end());

    cout << str << endl;

    return 0;
}
