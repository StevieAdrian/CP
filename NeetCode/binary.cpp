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

int search(vector<int> n, int target){
    int low = 0;
    int high = n.size() - 1;

    while (low <= high) {
        int mid = ((high - low) / 2) + low;

        if (n[mid] == target) {
            return mid;
        }

        if (n[mid] > target ){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main(){
    vector<int> n = {-1, 0, 2, 4, 6, 8};

    int target = 4;

    int solve = search(n, target);
    cout << solve << endl;
}