#include<iostream>
#include<map>

using namespace std;

int main(int argc, char const *argv[])
{
    map<string, string> countryCapital = {
        {"india", "new delhi"},
        {"netherlands", "amsterdam"} 
    };

    for(map<string,string>::iterator it = countryCapital.begin(); it != countryCapital.end(); it++){
        cout << (*it).first << " : " << (*it).second << endl;  
    }

    for (auto i : countryCapital)
    {
        cout << i.first << " : " << i.second <<endl;
    }
    

    if(countryCapital.find("india") != countryCapital.end()){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }

    return 0;
}
