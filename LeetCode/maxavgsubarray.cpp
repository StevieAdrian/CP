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

double solve(vector<int> n, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += n[i];
    }

    double maxx = (double)sum / k;
    for (int i = k, j = 0; i < n.size(); i++, j++) {
        sum = sum - n[j] + n[i];
        double avg = (double)sum / k;
        maxx = max(maxx, avg);
    } 

    return maxx;
}

int main(){
    vector<int> n = {5};
    int k = 1;

    cout << solve(n, k) << endl;
}