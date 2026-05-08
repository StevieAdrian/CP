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

ll gcd(ll a, ll b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll min(ll a, ll b){
    return (a < b) ? a : b;
}

pair<ll,ll> toFrac(string X){
    ll pred = 0, pem = 1;
    
    bool flag = false;
    int count = 0;

    for(auto c : X){
        if(c == '.'){
            flag = true;
            continue;
        }
        pred = pred * 10 + (c - '0');
        if(flag) count++;
    }

    while(count--) pem *= 10;

    ll gecede = gcd(pred,pem);
    return {pred/gecede, pem/gecede};
}

int main(){
    string iniUntukX;
    cin >> iniUntukX;
    ll iniL,iniR;
    cin >> iniL >> iniR;

    auto [p,q] = toFrac(iniUntukX);

    ll multiK = -1;
    ll multiS = -1;

    for (ll mult = 1; mult <= 100000; mult++) {
        ll k = q * mult;
        ll s = p * mult;

        debug(k);
        debug(s);
        
        if (s >= k * iniL && s <= k * iniR) {
            multiK = k;
            multiS = s;
            break;
        }
    }

    // if(multiS < multiK * iniL || multiS > multiK * iniR){
    //     cout << "-1\n"; return 0;
    // }


    if (multiK == -1) {
        cout << "-1" << endl;
        return 0;
    }

    vector<ll> ans(multiK, iniL);

    ll diff = multiS - multiK * iniL;
    ll addition = iniR - iniL;

    for(int i=0;i<multiK && diff > 0;i++){
        ll inc = min(addition, diff);
        ans[i] += inc;
        diff -= inc;
    }

    if(diff != 0){
        cout << "-1\n"; return 0;
    }

    cout << multiK << "\n";
    for(auto i : ans) cout << i << " ";
    cout << "\n";

    return 0;
}