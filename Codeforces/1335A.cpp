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

    for (int i = 0; i < n; i++){
        cin >> m;

        if (m <= 2) {
            m = 0;
        } else {
            if (m % 2 == 0) {
                m -= 1;
            }
            m /= 2;
        }
        
        cout << m << endl;
    }
}


/*
a > b
a + b = n

a = n - b

a > b
n - b > b
n > 2b 
b < n/2
========
b < n/2
=========


*/