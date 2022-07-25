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

int main(){
    string S,ans;
    cin >> S;
    int n = S.size();

    rep(i,n){
        if(S[n-i-1]=='.'){
            rep(j,i+1){
                S.pop_back();
            }
            break;
        }
    }
    cout << S << endl;
}