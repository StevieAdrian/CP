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

bool search(vector<vector<int>> matrix, int target) {
    // cout << matrix.size() << endl << matrix[1].size();
    int trow = matrix.size();
    int tcol = matrix[0].size();

    int low = 0;
    int high = trow * tcol - 1;
    while (low <= high) {
        int mid = ((high - low) / 2) + low;
        // debug(high); debug(low);
        // debug(mid);

        int col = mid / tcol;
        int row = mid % tcol;
        // debug(col);
        // debug(row);

        if (matrix[col][row] == target) return true;
        // debug(matrix[row][col]);
        if (matrix[col][row] > target) high = mid - 1;
        if (matrix[col][row] < target) low = mid + 1;
    }

    return false;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    // debug((1-0)/2 + 1);
    cout << search(matrix, target) << endl;
}