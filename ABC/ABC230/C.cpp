#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//
 
int main() {
    ll N,A,B,P,Q,R,S;
    cin >> N >> A >> B >> P >> Q >> R >> S;

    for(ll i=P;i<=Q;++i){
        for (ll j=R;j<=S;++j){
            char c = '.';
            // 操作1で埋まっているか?
            if (i== j+A-B) c = '#';
            // 操作2で埋まっているか?
            if (i==-j+A+B) c = '#';

            cout << c ;
        }
        cout << endl;
    }
}