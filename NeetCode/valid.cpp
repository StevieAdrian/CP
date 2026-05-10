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

bool solve(string s, string t){
    unordered_map<char, int> mp1, mp2;
    
    for(int i = 0; i < s.size(); i++){
        mp1[s[i]]++;
    }

    for(int i = 0; i < t.size(); i++){
        mp2[t[i]]++;
    }

    bool flag = true;

    if (mp1.size() != mp2.size()) {
        flag = false;
    }

    for (auto p: mp1) {
        if (p.second != mp2[p.first]) {
            flag =  false;
        }
    }

    return flag;
}

int main(){
    string s = "a";
    string t = "ab";

    cout << solve(s, t) << endl;
}