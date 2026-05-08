#include <iostream>
#include <queue>
#include <utility>
#include <stack>
#include <vector>
#include <string.h>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define int long long int
#define pb push_back
#define ld long double


int max(int a, int b){
    return (a > b) ? a : b;
}

signed main(){
    int iniN;
    cin >> iniN;

    vector<int> arr(iniN+1);
    for(int i=0;i<iniN;i++){
        cin >> arr[i];
    }

    bool flag = 1;
    for(int i=0;i<iniN-1;i++){
        if(arr[i] != arr[i+1]){
            flag = 0;
            break;
        }
    }

    if(flag){
        cout << "0\n";
        return 0;
    }

    int prevDir = 0;
    int changes = 0;

    for(int i=0;i<iniN-1;i++){
        int diff = arr[i+1] - arr[i];
        if(diff == 0) continue; // kalau grafiknya flat, gak usah di ganti
        int currDir = (diff > 0 ? 1 : -1);
        // kalau ada berubah, cek asal gak dari flat
        if(prevDir != 0 && currDir != prevDir){
            changes++;
        }
        prevDir = currDir;
    }

    int countSeharusnya = changes+1;
    map<int, int> freq;
    for(int i=0;i<iniN;i++){
        freq[arr[i]]++;
    }

    int makss = 0;
    for(auto p : freq){
        makss = max(makss, p.second);
    }
    
    int parityMoreLikeParentalIssue = 0;
    if(arr[0] == arr[iniN-1]){
        for(auto p : freq){
            if(p.first != arr[0] && (p.second % 2 == 1)){
                parityMoreLikeParentalIssue++;
            }
        }
    }

    cout << max(makss + parityMoreLikeParentalIssue, countSeharusnya) << "\n";
    return 0;
}