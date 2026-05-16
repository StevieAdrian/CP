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

vector<int> solve(vector<int>& n, int target) {
    vector<int> ans;
    int left = 0, right = n.size() - 1;
    // debug(n[left]);
    // debug(n[right]);
    while (left < n.size()){
        // debug(right);
        if (n[left] + n[right] == target){
            // debug(n[left]);
            return {left + 1, right + 1};
        }

        if (n[left] + n[right] > target) {
            right--;
        } else {
            left++;
        }
    }

    return {0, 0};
}

int main(){
    vector<int> n = {1, 2, 3, 4};
    int target = 3;

    vector<int> ans = solve(n, target);

    for (auto p: ans){
        cout << p << " " << endl;
    }
}