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

string solve(string s){
    int len = 0;
    ll maxx = MIN;
    int start = 0;

    for (int i = 0; i < s.size(); i++) {
        int left = i;
        int right = i;

        while (left >= 0 && right < s.size()) {
            if (s[left] == s[right]) {
                len = max(len, right - left + 1);
                if (len > maxx) {
                    maxx = len;
                    start = left;
                }
                left--; 
                right++;
            } else {
                break;
            }

        }

        left = i;
        right = i+1;
        while (left >= 0 && right < s.size()) {
            if (s[left] == s[right]) {
                len = max(len, right - left + 1);
                if (len > maxx) {
                    maxx = len;
                    start = left;
                }
                left--; 
                right++;
            } else {
                break;
            }

        }
    }

    return s.substr(start, maxx);
}

int main(){
    string s = "babad";
    
    cout << solve(s);

    return 0;
}