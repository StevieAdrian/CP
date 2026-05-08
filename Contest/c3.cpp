#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

signed main(){
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
    
    int maxfreq = 0;
    int ctr = 0;
    
    bool flag2 = (arr[0] == arr[n-1]);
    
    for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
        int val = it->first;
        int cnt = it->second;
        
        if(cnt > maxfreq) {
            maxfreq = cnt;
        }

        if(flag2 && val != arr[0] && cnt % 2 == 1){
            ctr++;
        }
    }
    
    int res1 = t + 1;
    int res2 = maxfreq + ctr;
    
    int ans = (res1 > res2) ? res1 : res2;
    cout << ans << "\n";
    
    return 0;
}   