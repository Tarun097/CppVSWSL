#include<iostream>
#include<utility>
#include<string>

using namespace std;


bool isPallindrome(string s, int i, int n){
    
    if(i>= n/2) return true;

    if(s[i] != s[n-i-1]) return false; 

    return isPallindrome(s, i+1, n);

}


int main(int argc, char const *argv[])
{
    string s = "MADAN";

    cout << std::boolalpha <<isPallindrome(s, 0, s.length());

    return 0;
}
