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

vector<vector<string>> solve(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < strs.size(); i++){
        // string res = sort(strs[i].begin(), strs[i].end());    
        string res = strs[i];
        sort(res.begin(), res.end());
        mp[res].push_back(strs[i]);
    }

    vector<vector<string>> res;

    for (auto p: mp) {
        res.push_back(p.second);
    }
    
    return res;
}

int main(){
    
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    vector<vector<string>> ans = solve(strs);

    for (auto v: ans) {
        for (auto s: v) {
            cout << s << " ";
        }
        cout << endl;
    }
}