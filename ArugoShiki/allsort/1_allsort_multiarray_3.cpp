#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int X,Y,Z;
int A[110],B[110],C[110];

int main() {
    
    cin >> X >> Y >> Z;
    rep(i,X) cin >> A[i];
    rep(i,Y) cin >> B[i];
    rep(i,Z) cin >> C[i];
    
    int cnt = 0;
    rep(i,X){
        rep(j,Y){
            rep(k,Z){
                if (A[i]+B[j]==C[k]){
                    cnt++;
                }
            }
        }
    }
	
    cout << cnt << endl;
    return 0;
}