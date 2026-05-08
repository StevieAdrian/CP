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

    char m;
    int r;
    for (int i = 0; i < n; i++){
        cin >> m >> r;  

        for (char j = 'a'; j <= 'h'; j++){
            if (j != m) {
                cout << j << r << endl;
            }
        }

        for (int j = 1; j <= 8; j++){
            if (j != r){
                cout << m << j << endl;
            }
        }
    }
}