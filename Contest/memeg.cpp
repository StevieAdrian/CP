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
using pl = pair<ll,int>;

const ll MAX = LLONG_MAX;
const ll MIN = LLONG_MIN;
const ll INF = (1LL<<62);

struct wtever {
    int to;
    int id;
    ll w;
};

void djik1(int l, const vector<vector<wtever>>& all, vector<ll>& ctr, vector<int>& he) {
    int n = all.size() - 1; 

    ctr.assign(n + 1, INF);
    he.assign(n + 1, -1);
    ctr[l] = 0;

    priority_queue<pair<ll,int>, 
    vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, l});

    while (!pq.empty()) {
        pair<ll,int> top = pq.top();
        pq.pop();

        ll curr = top.first;
        ll curr2 = top.second;

        if (curr != ctr[curr2]) {
            // debug(curr);
            continue;
        }

        for (int i = 0; i < (int)all[curr2].size(); ++i) {
            wtever temp = all[curr2][i];
            int ct = temp.to;
            ll berat = temp.w;

            if (ctr[ct] > curr + berat) {
                ctr[ct] = curr + berat;
                he[ct] = temp.id;
                // debug(he[ct]);
                pq.push({ctr[ct], ct});
            } 
            // else {
            //     cout << "tes debug" << endl;
            // }
        }
    }
}

void djik2(int n, int src, const vector<vector<wtever>>& g2, vector<ll>& dist) {
    dist.assign(n + 1, INF);
    dist[src] = 0;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<ll,int> topElem = pq.top();
        pq.pop();

        ll curr = topElem.first;
        ll u = topElem.second;

        if (curr != dist[u]) {
            continue;
        }
        
        for (int i = 0; i < (int)g2[u].size(); ++i) {
            wtever e = g2[u][i];
            int v = e.to;
            ll w = e.w;

            if (dist[v] > curr + w) {
                dist[v] = curr + w;
                pq.push({dist[v], v});
            }
            // else {
                // debug(i);
            // }
        }
    }
}

int main() {
    int n, m;

    if (!(cin >> n >> m)) return 0;
    
    vector<int> edge1(m+1), edge2(m+1);
    vector<ll> W(m+1);
    vector<vector<wtever>> g(n+1);

    for (int i = 1; i <= m; ++i) {
        // if (u && w){
        //    g[u].pus
        // }
        int u;
        int v; 
        ll w;
        cin >> u >> v >> w;
        
        edge1[i] = u; 
        edge2[i] = v; 
        W[i] = w;
        g[u].push_back({v, i, w});
        g[v].push_back({u, i, w});
    }

    vector<ll> dist1; vector<int> parent1;
    djik1(1, g, dist1, parent1);

    if (dist1[2] >= INF/2) {
        cout << "-1" << endl;
        return 0;
    }

    vector<char> flag(m+1, 0);
    ll cost12 = dist1[2];
    int cur = 2;
    while (cur != 1) {
        int eid = parent1[cur];
        if (eid == -1) {
            break;
        }
        flag[eid] = 1;
        int a = edge1[eid];
        int b = edge2[eid];

        cur = (cur == a) ? b : a; 
    }

    fill(flag.begin(), flag.end(), 0);
    cur = 2;
    vector<int> visitedNode(n+1, 0);
    while (cur != 1) {
        int eid = parent1[cur];
        if (eid == -1) {
            break;
        }
        
        flag[eid] = 1;

        int a = edge1[eid];
        int b = edge2[eid];
        int parentNode = (cur == a) ? b : a;

        cur = parentNode;
    }

    vector<vector<wtever>> g2(n+1);
    for (int i = 1; i <= n; ++i) {
        for (auto &e: g[i]) {
            int id = e.id;
            ll lele = W[id];
            if (flag[id]) {
                ll lele2 = (lele + 1) / 2;
                g2[i].push_back({e.to, id, lele2});
            } else {
                g2[i].push_back({e.to, id, lele});
            }
        }
    }

    vector<ll> res2;
    djik2(n, 2, g2, res2);

    if (res2[3] >= INF/2) {
        cout << "-1" << endl;;
        return 0;
    }

    ll total = cost12 + res2[3];
    cout << total << endl;

    return 0;
}
