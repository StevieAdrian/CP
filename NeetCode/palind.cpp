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

bool solve(string s) {
    string clean = "";
    for (char c: s) {
        if (isalnum(c)) {
            clean += tolower(c);
        }
    }

    // start dari true (asumsi semuanya palindrome), karna klo dari false, bisa aja semuanya false dan string terakhir sama, jadinya bikin flag true
    // bool flag = true;
    for (int i = 0, j = clean.size() - 1; i < clean.size() / 2; i++, j--) {
        if (clean[i] != clean[j]) {
            return false;
        } 
    }

    return true;
}

int main(){
    
    string s = "Was it a car or a cat I saw?";
    
    cout << solve(s) << endl;
}