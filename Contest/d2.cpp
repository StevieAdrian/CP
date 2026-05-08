#include <bits/stdc++.h>

// #ifndef ONLINE_JUDGE
// #include "template.cpp"
// #else
// #define debug(...)
// #define debugArr(...)
// #endif

using namespace std;
using ll = long long;
using ld = long double;

vector<ll> dijkstra(int re, const vector<vector<pair<int,ll>>>& g) {
    int n = g.size() - 1;
    vector<ll> dist(n + 1, LLONG_MAX);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    dist[re] = 0;
    pq.push({0, re});

    while (!pq.empty()) {
        pair<ll,int> top = pq.top();
        pq.pop();

        ll atas = top.first;
        int atas2 = top.second;

        if (atas != dist[atas2]) {
            continue;
        }

        for (int i = 0; i < (int)g[atas2].size(); ++i) {
            pair<int,ll> p = g[atas2][i];
            ll yeye = p.first;
            ll yeye2 = p.second;
            ll atasujung = atas + yeye2;

            if (atasujung < dist[yeye]) {
                dist[yeye] = atasujung;
                pq.push({atasujung, yeye});
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,ll>>> g(n+1), gb(n+1);
    
    for (int i = 0; i < m; i++) {
        ll r, s, t;
        cin >> r >> s >> t;
        ll midd = ceil((double) t/ 2);
        // ll midd = (t + 1) /2;
        ll hf = t + midd;  
        // debug(midd, hf);
        
        g[r].push_back({s, t});
        g[s].push_back({r, t});
        gb[r].push_back({s, hf});
        gb[s].push_back({r, hf});
    }
    
    vector<ll> g1 = dijkstra(1, g);
    vector<ll> g2 = dijkstra(3, g);
    vector<ll> g3 = dijkstra(2, gb);
    
    ll total = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        if (g1[i] == LLONG_MAX / 2 || g2[i] == LLONG_MAX / 2 || g3[i] == LLONG_MAX / 2) {
            continue;
        }
        // debug(g1);
        // debug(g2);
        // debug(g3);

        total = min(total, g1[i] + g2[i] + g3[i]);
    }
    
    cout << total << endl;

    return 0;
}