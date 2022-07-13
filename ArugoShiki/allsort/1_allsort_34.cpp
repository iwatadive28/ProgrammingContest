#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

string S;
char c[110];

int main() {
	cin >> S ;
    
    int cnt = 1;
    c[0] = S[0];
    for(int i=1;i<S.length();++i){
        bool unq = true;
        rep(j,cnt){
            if (S[i]==c[j]){
                unq = false;
                break;
            }
        }
        if (unq){
            c[cnt] = S[i];
            cnt++;
            // printf("i=%d,cnt=%d,%c\n",i,cnt,S[i]);
        }
    }

    cout << cnt << endl;
    return 0;
}