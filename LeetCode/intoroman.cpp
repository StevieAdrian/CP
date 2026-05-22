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

string solve(int n) {
    vector<pair<int, string>> roman = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    string ans = "";

    for (auto [value, symbol] : roman) {
        while (n >= value) {
            ans += symbol;
            n -= value;
        }
    }

    return ans;
}

int main(){
    int n = 1994;
    // string ans = "";

    // while (n != 0) {
    //     if (n >= 1000) {
    //         ans += "M";
    //         n -= 1000;
    //     } else if (n >= 900) {
    //         ans += "CM";
    //         n -= 900;
    //     } else if (n >= 500) {
    //         ans += "D";
    //         n -= 500;
    //     } else if (n >= 400) {
    //         ans += "CD";
    //         n -= 400;
    //     } else if (n >= 100) {
    //         ans += "C";
    //         n -= 100;
    //     } else if (n >= 90) {
    //         ans += "XC";
    //         n -= 90;
    //     } else if (n >= 50) {
    //         ans += "L";
    //         n -= 50;
    //     } else if (n >= 40) {
    //         ans += "XL";
    //         n -= 40;
    //     } else if (n >= 10) {
    //         ans += "X";
    //         n -= 10;
    //     } else if (n >= 9) {
    //         ans += "IX";
    //         n -= 9;
    //     } else if (n >= 5) {
    //         ans += "V";
    //         n -= 5;
    //     } else if (n >= 4) {
    //         ans += "IV";
    //         n -= 4;
    //     } else if (n >= 1) {
    //         ans += "I";
    //         n -= 1;
    //     }
    // }

    cout << solve(n) << endl;
}