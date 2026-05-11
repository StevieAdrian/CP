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

vector<int> solve(vector<int>& nums) {
    vector<int> pref(nums.size());
    vector<int> suff(nums.size(), 1);

    pref[0] = nums[0];
    suff[nums.size() - 1] = nums[nums.size() - 1];

    for (int i = 1; i < nums.size(); i++) {
        pref[i] = pref[i-1] * nums[i];
    }

    for (int i = nums.size() - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] * nums[i];
    }

    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) res[i] = suff[i+1];
        else if (i == nums.size() - 1) res[i] = pref[i-1];
        else res[i] = pref[i-1] * suff[i+1];
    }

    // for (auto s: suff) {
    //     debug(s);
    // }

    return {res};
}

int main(){
    vector<int> nums = {4,3,2,1,2};

    // solve(nums);

    vector<int> res = solve(nums);    
    for (auto p: res) {
        cout << p << endl;
    }

    return 0;
}