#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<ll> cnt(N+1,0);
    vector<string> ans;
    rep(i,Q){
        ll c,x;
        cin >> c >> x;
        if(c==3){
            if(cnt[x]>=2) ans.push_back("Yes");
            else          ans.push_back("No");
        }else{
            cnt[x]+=c;        
        }
    }

    rep(i,ans.size()) cout << ans[i] << endl;
}