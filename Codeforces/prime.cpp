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
    int n;
    cin >> n;
    int count = 0;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            cout << "bkn" << endl;
            return 0;
        } 
    }

    // if (count == 2) {
        cout << "prime" << endl;
    // } 
    // else {
    //     cout << "bkn" << endl;
    // }

    return 0;
}