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

bool solve(vector<int>& n) {
    
    unordered_map<int, int> mp;
    for (int i = 0; i < n.size(); i++) {
        mp[n[i]]++;
    }

    for (auto p : mp) {
        if (p.second > 1) {
            return true;
        }
    }

    return false;
}

int main(){
    
    vector<int> n = {9, 1, 2, 4, 3};

    cout << solve(n);

    return 0;
}