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

int solve(string s) {
    unordered_map<char, int> dup;
    int count = 0, l = 0;

    for (int r = 0; r < s.length(); r++){
        dup[s[r]]++;

        while (dup[s[r]] > 1) {
            // cout << dup[s[r]];
            dup[s[l]]--;
            l++;
            // debug(l);
        }
        
        count = max(count, r - l + 1);
        // debug(count);
    }
    
    return count;
}
int main(){
    string s = "pwwkew";
    // string s = "zxyzxyz";
    
    cout << solve(s) << endl;
}