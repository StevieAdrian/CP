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

vector<int> twoSums(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++){
        int ctx = target - nums[i];

        // debug(mp[i]);
        // debug(ctx, mp[ctx], mp[nums[i]], i, nums[i]);
        if (mp.find(ctx) != mp.end()) {
            // debug(mp[ctx], i);
            return {mp[ctx], i};
        } else {
            mp[nums[i]] = i;
        }
    }

    return {};
}

int main(){
    
    vector<int> n = {-1,-2,-3,-4,-5};
    int target = -8;

    vector<int> result = twoSums(n, target);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}