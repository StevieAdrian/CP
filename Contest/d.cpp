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
const ll INF = (ll)4e18;

const ll MAX = LLONG_MAX;
const ll MIN = LLONG_MIN;

vector<ll> dijkstra(int src, const vector<vector<pair<int,ll>>>& g) {
    int n = g.size() - 1;
    vector<ll> dist(n+1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) {
            ll nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    if (!(cin >> N >> M)) return 0;
    
    vector<vector<pair<int,ll>>> temp(N+1), g_bundle(N+1);
    
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        ll half_up = (w + 1) / 2;         
        ll bundle = w + half_up;  
        
        temp[u].push_back({v, w});
        temp[v].push_back({u, w});
        
        g_bundle[u].push_back({v, bundle});
        g_bundle[v].push_back({u, bundle});
    }
    
    vector<ll> d1 = dijkstra(1, temp);
    vector<ll> d3 = dijkstra(3, temp);
    vector<ll> db = dijkstra(2, g_bundle);
    
    ll ans = INF;
    for (int v = 1; v <= N; v++) {
        if (d1[v] == INF || d3[v] == INF || db[v] == INF) continue;
        ans = min(ans, d1[v] + d3[v] + db[v]);
    }
    
    cout << ans << "\n";
    return 0;
}