#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main()
{
    int n, m;
    cin >> n;

    while(n--){
        cin >> m;

        if (m % 3 == 0){
            cout << "0" << endl;
        } else if (m % 3 == 1){
            cout << "2" << endl;
        } else if (m % 3 == 2){
            cout << "1" << endl;
        }
    }
}