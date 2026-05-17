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

vector<vector<int>> solve(vector<int> n){
    vector<vector<int>> ans;
    sort(n.begin(), n.end());
    
    for (int i = 0; i < n.size(); i++){
        int l, r = n.size() - 1;
        if (i > 0 && n[i] == n[i-1]) continue;
        if (i != r) l = i + 1;
        
        if (n[i] == 0 && n[l] == 0 && n[r] == 0){
            return {{0, 0, 0}};
        }

        // debug(i); debug(l); debug(r);

        while (l < r){
            if (n[i] + n[l] + n[r] < 0) {
                l++;
            } else if (n[i] + n[l] + n[r] > 0){
                r--;
            } else {
                ans.push_back({n[i], n[l], n[r]});
                
                while (n[l] == n[l+1]) l++;
                while (n[r] == n[r-1]) r--;

                l++;
                r--; 
            }
            // debugArr(n[l]);
        }
        
    }

    return {ans};
}

int main(){
    vector<int> n = {-2, 0, 0, 2, 2};
    // vector<int> n = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = solve(n);
    for (auto p : ans){
        for (auto x : p){
            cout << x << " ";
        }
        cout << endl;
    }
}