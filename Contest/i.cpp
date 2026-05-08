#include <iostream>
#include <vector>
using namespace std;

#define ll long long int
#pragma GCC optimize ("O3")

const int sz = 1e3 + 5;
char map[sz][sz];


bool isValid(int x, int y){
    bool case1 = (map[x][y] == '.');
    bool case2 = (map[x][y+1] == '.');
    bool case3 = (map[x+1][y] == '.');
    bool case4 = (map[x+1][y+1] == '.');
    
    int dot = case1 + case2 + case3 + case4;

    if(dot == 3) return true;

    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int iniN, iniM;
    cin >> iniN >> iniM;
    
    for(int i=0;i<iniN;i++){
        cin >> map[i];
    }

    ll invalid = 0;
    if(iniN >= 2 && iniM >= 2){
        for (int i = 0; i < iniN - 1; i++) {
            for (int j = 0; j < iniM - 1; j++) {
                invalid += isValid(i, j);
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int x, y;
        cin >> x >> y;
        --x;
        --y;

        for(int dirX = -1; dirX<= 0; dirX++){
            for(int dirY= -1; dirY <= 0; dirY++){
                int xx = x + dirX;
                int yy = y + dirY;
                if(xx >= 0 && xx + 1 < iniN && yy >= 0 && yy + 1 < iniM) invalid -= isValid(xx,yy);
            }
        }

        if(map[x][y] == '.') map[x][y] = '#';
        else map[x][y] = '.';

        for(int dirX = -1; dirX<= 0; dirX++){
            for(int dirY= -1; dirY <= 0; dirY++){
                int xx = x + dirX;
                int yy = y + dirY;
                if(xx >= 0 && xx + 1 < iniN && yy >= 0 && yy + 1 < iniM) invalid += isValid(xx,yy);
            }
        }
        cout << ((invalid == 0) ? "RECTANGLES" : "NO") << '\n';
    }

    return 0;
}