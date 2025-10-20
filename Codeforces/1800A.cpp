#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main()
{
    int n, m;
    cin >> n; getchar();
    
    char r[55] = "";
    char curr;
    string dict = "meow";
    
    for (int i = 0; i < n; i++){
        cin >> m; getchar();
        int count = 0;
        int idx1 = -1, idx2 = -1;
        bool seen[5] = {false, false, false, false};
        for (int j = 0; j < m; j++){
            cin >> r[j];
        }
        r[m] = '\0';

        for (int j = 0; j < strlen(r); j++) {
            char temp = tolower(r[j]);
            // debug(temp);
            curr = temp;
            
            if (curr != 'm' && curr != 'e' && curr != 'o' && curr != 'w') {
                count--;
                break;
            }

            // debug(curr);
            for (int k = 0; k < dict.length(); k++){
                if (dict[k] == curr){
                    idx1 = k;
                    break;
                } 
            }

            if (idx1 < 0 || idx1 < idx2 || idx1 > idx2 + 1){
                count--;
                break;  
            }
            
            seen[idx1] = true;
            idx2 = idx1;
        }
    
        if (tolower(r[0]) != 'm' || tolower(r[m-1]) != 'w'){
            count--;
        }

        for (int j = 0; j < 4; j++){
            if (seen[j] == true){
                count++;
            }
        }
        
        if (count == 4){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
}