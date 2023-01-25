#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
ll cnt_kaibun(string s){
    ll M = s.size();
    ll res = 0;  
    if(M <= 1)  return true;   
    
    rep(i,M/2){
        if (s[i] == s[M-1-i]) res++;
    }
    return res;
}

bool kaibun(string s){
    ll M = s.size();
    if(M <= 1)  return true;   
    
    rep(i,M/2){
        if (s[i] != s[M-1-i]) return false;
    }
    return true;
}

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    
    if(kaibun(S)){
        cout << 0 << endl;
        return 0;
    }

    ll ans = B*(N/2-cnt_kaibun(S));
    // A 操作をN回繰り返して、一致する文字があるか確認する
    rep(i,N){
        S = S.substr(1,N)+S[0];
        ll cost = A*(i+1) + B*(N/2-cnt_kaibun(S));       
        // cout << i << ": "<< S << "," << cnt_kaibun(S) << "," << cost << endl;
        chmin(ans,cost); 
    }
    cout << ans << endl;
}
