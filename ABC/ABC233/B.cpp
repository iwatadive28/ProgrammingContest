#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    int L,R;
    string S;
    cin >> L >> R;
    --L;--R;
    cin >> S;
    
    string ans = S;
    rep(i,S.length()){
        if(i>=L & i<=R){
            ans[i] = S[R+L-i];
            ans[R+L-i] = S[i];
        }
    }

    cout << ans << endl;
}