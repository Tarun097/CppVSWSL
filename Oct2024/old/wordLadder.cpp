#include<iostream>
#include<unordered_set>
#include<queue>
#include<string>
#include<utility>

using namespace std;


int wordLadderCount(string beginWord, string endWord, vector<string>& wordList){

    unordered_set<string> s(wordList.begin(), wordList.end());
    queue<pair<string,int>> q;

    q.push({beginWord,1});
    s.erase(beginWord);

    while (!q.empty())
    {
        string currWord = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(currWord==endWord) return steps;

        for(int i=0; i< currWord.size(); i++){ //word length
            char original = currWord[i];
            
            for(char c='a'; c<='z'; c++){ //replace ith letter of word with all alphabets

                currWord[i]=c;
                if(s.find(currWord) != s.end()){
                    s.erase(currWord);
                    q.push({currWord, steps+1});
                }
            }

            currWord[i] = original; //restore the original alphabet
        }

    }

    return 0;

}


int main(int argc, char const *argv[])
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << wordLadderCount(beginWord, endWord, wordList);

    return 0;
}