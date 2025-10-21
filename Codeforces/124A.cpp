#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

using namespace std;
using ll = long long;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int x1 = a + 1;
    int x2 = n - b;
    // debug(x1);
    // debug(x2);

    int c1 = max(x1, x2);
    int c2 = n - c1 + 1;
    // debug(c1, c2);
    
    cout << c2 << endl;
}

/*
5 2 3
gk kurang dari 2 org didepan -> min 2
gk lebih dari 3 org di belakang -> max 3


x - 1 >= a
n - x >= b

9 4 3
  a b
O O O O O | O O O

19: [x1 = 5]
20: [x2 = 6]
24: [c1 = 5 || c2 = 6]

O O O O | O O O O X -> max 3
O O O O O | O O O  1
O O O O O O | O O  2
O O O O O O O | O  3
O O O O O O O O |  4

1  2  3  4  5 | 6  7  8  9
               ^---------^
                posisi valid

9 - 6 + 1 = 4
total = (posisi terakhir) - (posisi pertama) + 1

intinya tinggal ngitung c1 sampe n

q1 = max (x1, x2) -> peter mulai baris
q2 = n - q1
*/