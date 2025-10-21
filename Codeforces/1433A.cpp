#include <bits/stdc++.h>
using namespace std;
#include <vector>
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)

#endif

signed main()
{
    int n, m;
    vector<int> arr = {1, 2, 3, 4};
    cin >> n;


    while (n--) {
        cin >> m;
        int temp = m;
        int temp2 = m % 10; 
        int count = 0;

        while (temp != 0) {
            temp /= 10;
            count++;
            debug(count);
        }

        int digit = 10*(temp2 - 1);
        
        for (int i = 0; i < count; i++){
            digit += arr[i];
            // debug(digit);
        }
        
        cout << digit<< endl;
    }
}