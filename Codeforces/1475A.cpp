#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;

    ll m;
    
    while(n--){
        cin >> m;
        bool flag = false;

        if  (m == 1) {
            flag = false;
        }

        if (m % 2 == 1){
            flag = true;
        }

        for (ll i = 3; i <= sqrt(m); i += 2){
            if (m % i == 0){
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}