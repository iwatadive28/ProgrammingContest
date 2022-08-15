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
//
int main(){
    string ref = "atcoder";
    string S;
    cin >> S;
    vector<int> idx(7);
    rep(i,7) rep(j,7) if(ref[i]==S[j]) idx[i]=j;
    
    ll ans = 0;    
    rep(ii,7){
        int tmp = idx[ii];
        while(S[ii]!=ref[ii]){
            swap(S[tmp],S[tmp-1]);
            tmp--;
            ans++;
        }
        rep(i,7) rep(j,7) if(ref[i]==S[j]) idx[i]=j;
    }   

    cout << ans << endl;
}
