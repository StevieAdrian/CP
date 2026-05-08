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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0;i< n; i++){
        cin >> arr[i];
    }
    
    bool flag = true;
    for (int i = 1; i < n; i++){
        if(arr[i] != arr[0]){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << 0 << "\n";
        return 0;
    }
    
    int t = 0;
    int t2 = 0;
    for(int i = 0; i < n-1; i++){
        int diff = arr[i+1] - arr[i];
        if(diff == 0) {
            continue;
        }
        // debug(diff);
        int temp = (diff > 0) ? 1 : -1;
        if(t2 != 0 && temp != t2){
            t++;
        }
        t2 = temp;
    }
    
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    
    int mx = 0;
    int ctr = 0;
    
    bool flag2 = (arr[0] == arr[n-1]);
    
    for(auto p : freq){
        int val = p.first;
        int cnt = p.second;
        
        if(cnt > mx) {
            mx = cnt;
        }

        if(flag2 && val != arr[0] && cnt % 2 == 1){
            ctr++;
        }
    }
    
    int res1 = t + 1;
    int res2 = mx + ctr;
    // debug(res1);
    // debug(res2);
    // debug(ctr);
    // debug(mx);
    
    int ans = (res1 > res2) ? res1 : res2;
    cout << ans << "\n";
    
    return 0;
}