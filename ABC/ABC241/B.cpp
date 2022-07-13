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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N),B(M);
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];

    map<ll,ll> mp;
    // 見つからない場合はcnt1で初期化
    rep(i,N){
        if (mp.find(A[i]) == mp.end()){
            mp[A[i]] = 1;
        }else{
            ++mp[A[i]];
        }    
    }

    bool ans = true;
    rep(i,M){
        // 見つからない場合、もしくはcnt=0の場合はFalse
        if (mp.find(B[i]) == mp.end() || mp[B[i]] == 0 ){
            ans = false;
            break;
        }else{
            --mp[B[i]];
        }
    }

    cout << (ans?"Yes":"No") << endl;
    
}