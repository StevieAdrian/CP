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


vector<int> solve(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    vector<vector<int>> bucket(nums.size()+1);

    for (auto p: mp) {
        bucket[p.second].push_back(p.first);
    }

    vector<int> result;

    // ini o(n) bukan o(n^2) karena loop kedua ga ngulagn sebanyak N, melainkan sebanyak jumlah bucket yg ada doang
    for (int i = bucket.size() - 1; i >= 0 && k > 0; i--) {
        for (auto num: bucket[i]) {
            result.push_back(num);
            k--;
            if (k == 0) break;
        }
    }
    /*
        1, 1, 1, 1, 2, 3, 3
        bucket[4] = 1
        bucket[1] = 2
        bucket[2] = 3
        
        print from biggest bucket size
    */
   return result;
}   

int main(){
    
    vector<int> n = {1,2,2,3,3,3};
    int k = 2;

    vector<int> result = solve(n, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}