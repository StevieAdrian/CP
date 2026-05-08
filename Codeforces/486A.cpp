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
    ll n;
    cin >> n;

    ll init;
    ll count = 0;

    if (n % 2 == 0){
        count = n / 2;
    } else {
        count = ((n+1)/2)*-1;
    }

    cout << count << endl; 
}

/*
2 = -1 + 2 = 1
4 = -1 + 2 -3 + 4 = 2
6 = -1 + 2 -3 + 4 -5 + 6 = 3
8 = -1 + 2 -3 + 4 -5 + 6 -7 +8 = 4


1 = -1
3 = -1 + 2 -3 = -2
5 = -1 + 2 -3 +4 -5 = -3
7 = -1 + 2 -3 +4 -5 +6 -7 = -4
*/