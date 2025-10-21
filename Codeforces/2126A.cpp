#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;

signed main()
{
    int n;
    cin >> n;
    int m;

    while(n--) {
        cin >> m;
        int temp = 0;
        ll temp2 = LLONG_MAX;

        while (m != 0) {
            temp = m % 10;
            if (temp2 > temp) {
                temp2 = temp;
            }
            m /= 10;
        }

        cout << temp2 << endl;
    }
}