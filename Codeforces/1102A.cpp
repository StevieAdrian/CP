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

    int t = n*(n+1) / 2;
    if (t % 2 == 0){
        cout << "0" << endl;
    } else {
        cout << "1" << endl;
    }
}