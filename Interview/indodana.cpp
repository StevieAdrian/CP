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

int main(){
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(m, vector<int>(n));

    int top = 0;
    int left = 0;
    int bottom = m-1;
    int right = n-1;
    int count = 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) graph[top][i] = count;
        top++; count++;

        for (int i = top; i <= bottom; i++) graph[i][right] = count;
        right--; count++;

        for (int i = left; i <= right; i++) graph[bottom][i] = count;
        bottom--; count++;

        for (int i = bottom; i >= top; i--) graph[i][left] = count;
        left++; count++;
    }

    for (auto x : graph) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}