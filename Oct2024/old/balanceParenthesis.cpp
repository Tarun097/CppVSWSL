#include<iostream>
#include<stack>
#include<string>
#include<map>

using namespace std;

int main(int argc, char const *argv[])
{
    string str = "()[{}()]";

    map<char, char> dict = {
        {'}','{'},
        {']','['},
        {')', '('}
    };

    stack<char> s;

    for(int i=0; i< str.size(); i++){

        char symbol = str[i];

        if(symbol == '(' || symbol == '[' || symbol == '{'){
            s.push(str[i]);
        }
        else if(symbol == ')' || symbol == ']' || symbol == '}'){
            if(s.top() == dict[symbol]){
                s.pop();
            }
        }
    }

    if(s.size() == 0){
        cout << "balanced" << endl;
    }
    else{
        cout << "Not balanced" << endl;
    }

    return 0;
}
