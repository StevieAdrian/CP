#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

using namespace std;
using ll = long long;
using ld = long double;

const ll MAX = LLONG_MAX;
const ll MIN = LLONG_MIN;

int solve(string begin, string end, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    queue<pair<string, int>> q;
    q.push({begin, 1});
    
    unordered_set<string> visited;
    visited.insert(begin);
    
    while (!q.empty()) {
        auto [word, level] = q.front();
        q.pop();
        
        for (int i = 0; i < word.length(); i++) {
            // string let = 'abcdefghijklmnopqrstuvwxyz';
            // for (int j = 1; j <= let.size(); j++){
            //     word[i]
            // }
            string original = word; 
            for (char letter = 'a'; letter <= 'z'; letter++) {
                word[i] = letter; 
                // debug(word[i]); break;
                
                if (wordSet.find(word) != wordSet.end() && visited.find(word) == visited.end()) {
                // if (find(wordList.begin(), wordList.end(), word) != wordList.end() && find(visited.begin(), visited.end(), word) == visited.end()) {      
                    if (word == end) {
                        // debug("in");
                        return level + 1;
                    }
                    
                    // debug(original);
                    q.push({word, level + 1});
                    visited.insert(word);
                }
            }
            word = original; 
        }
    }
    
    return 0;
}

int main(){
    string begin = "hit"; 
    string end = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << solve(begin, end, wordList) << endl;
}