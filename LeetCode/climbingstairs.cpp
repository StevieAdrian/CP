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

// top down
// int solve(int n) {
//     vector<int> dp(n+1);

//     if (n == 1) return 1;
//     if (n == 2) return 2;

//     if (dp[n] != 0) return dp[n];

//     return solve(n - 1) + solve(n - 2);
// }

// bototm up 
int solve(int n) {
    vector<int> dp(n+1);

    dp[1] = 1;

    if (n >= 2) dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(){
    int n = 5;
    
    cout << solve(n);
}