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

bool precedence(char a, char b){
    if ((a == '*' || a == '/') && (b == '+' || b == '-')) return true;
    if ((a == '+' || a == '-') && (b == '*' || b == '/')) return false;

    return true;
}


int main(){
    // d=
    string ctx;
    cin >> ctx;
        
    stack<int> num;
    stack<char> op;

    for (int i = 0; i < ctx.size(); i++){
        string temp;
        if (ctx[i] >= '0' && ctx[i] <= '9'){
            while (i < ctx.size() && ctx[i] >= '0' && ctx[i] <= '9'){
                temp += ctx[i];
                i++;
            } 
            num.push(stoi(temp));
        }

        if (op.empty()) {
            op.push(ctx[i]);
        } else {
            while (!op.empty() && precedence(op.top(), ctx[i])) {
                int a = num.top(); num.pop();
                int b = num.top(); num.pop();
    
                char tempOp = op.top(); op.pop();

                if (tempOp == '+') num.push(a + b);
                else if (tempOp == '-') num.push(b - a);
                else if (tempOp == '*') num.push(a * b);
                else if (tempOp == '/') num.push(b / a);
            }
            op.push(ctx[i]);
        }
    }
    
    cout << num.top();

    return 0;
}