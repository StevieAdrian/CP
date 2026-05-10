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

    vector<char> pls;
    vector<int> ded;

    for (int i = 0; i < n; i++){
        cin >> pls[i] >> ded[i];
    }

    while(m--) {
        int ctr1; char qq; int qqq;
        cin >> ctr1 >> qq >> qqq;
        
        pls[ctr1-1] = qq;
        ded[ctr1-1] = qqq;
        int count = 0;

        for (int i = 0; i < n; i++){
            if (pls[i] == '+') {
                count = count + ded[i] % 16;
            } else {
                count = count ^ ded[i];
            }
        } 
        
        cout << count << endl;
    }
}