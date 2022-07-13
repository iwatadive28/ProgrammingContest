#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//

int main(){
    // INPUT
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];    
        
    // SORT
    vector<ll> b = a; 
    sort(b.begin(),b.end(),greater<ll>());
    
    // 重複を除く
    b.erase(unique(b.begin(), b.end()), b.end());

    // B の各要素が何番目かを連想配列に求めていく
    map<int,int> order;
    rep(i,b.size()){
        order[b[i]] = i;
    }
    // 再び A の各要素の順位を求めていく
    rep(i,N){
        cout << order[a[i]] << endl;
    }
     
    return 0;
}