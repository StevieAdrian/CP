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

int main() {
    string s; 
    cin >> s;
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    vector<int> odd;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 == 1) {
            odd.push_back(i);
        }
    }

    int k = max(1, (int)odd.size());
    cout << k << endl;

    if (odd.empty()) {
        string stengah = "";

        for (int i = 0; i < 26; ++i) {
            stengah += string(freq[i] / 2, 'a' + i);
        }

        string rev = stengah;
        reverse(rev.begin(), rev.end());
        cout << stengah + rev << endl;
        return 0;
    }

    for (int i : odd) freq[i]--;

    ll ctr1 = 0, ctr2 = 0;;
    for (int f : freq) ctr1 += f / 2;

    vector<string> left(k, "");
    for (int i = 0; i < 26; ++i) {
        while (freq[i] >= 2) {
            left[ctr2].push_back('a' + i);
            freq[i] -= 2;
            ctr2 = (ctr2 + 1) % k;
        }
    }

    for (int i = 0; i < k; ++i) {
        string rev = left[i];
        reverse(rev.begin(), rev.end());
        char mid = 'a' + odd[i];
        cout << left[i] + mid + rev << endl;
    }
}
