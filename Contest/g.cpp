#include <iostream>
#include <queue>
#include <utility>
#include <stack>
#include <vector>
#include <string.h>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#pragma GCC optimize ("O3")
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ld long double

bool isValid(int val, int k){
    return (0 <= val && val <= k);
}
int countt = 0;

unordered_map<int, vector<int>> ctr;

vector<int> solve(int val, int K) {
    auto it = ctr.find(val);
    if (it != ctr.end()) {
        return it->second;
    }

    vector<int> arr;
    arr.reserve(K + 1);
    for (int i = 0; i <= K; ++i){
        arr.push_back(val ^ i);
    }

    return ctr[val] = arr;
}

int main() {
    int iniQ, iniK;
    cin >> iniQ >> iniK;
    
    unordered_set<int> ust;
    unordered_map<int,int> mp;
    
    int initCover = 0;
    int currYval = 1;
    while(iniQ--){
        int val;
        cin >> val;

        bool isInsert = (ust.find(val) == ust.end());

        if(isInsert){
            ust.insert(val);
            vector<int> cache = solve(val, iniK);

            for(int it = 0; it <= iniK; it++){
                int resY = cache[it];
                int &mpc = mp[resY];
                ++mpc;
            }

            if(isValid(val, iniK)) initCover++;
        }else{
            if(isValid(val,iniK)) initCover--;
            
            vector<int> cache = solve(val, iniK);
            for(int it = 0; it <= iniK; it++){
                int resY = cache[it];
                int &mpc = mp[resY];
                --mpc;
            }
            ust.erase(val);
        }

        if(initCover != iniK + 1){
            cout << 0 << "\n";
            continue;
        }

        while(true){
            auto index = mp.find(currYval);
            int cc = (index == mp.end() ? 0 : index->second);
            if(cc < iniK + 1) break;
            currYval++;
        }
        cout << currYval << "\n";
    }
    return 0;
}