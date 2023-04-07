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
    ll L,N1,N2;
    cin >> L >> N1 >> N2;
    vector<pair<ll,ll>> vl1,vl2;
    rep(i,N1){
        ll v,l;
        cin >> v >> l;
        vl1.push_back({v,l});
    }
    rep(i,N2){
        ll v,l;
        cin >> v >> l;
        vl2.push_back({v,l});
    }

    ll i = 0,j = 0,p = 0, q = 0;
    ll ans = 0;
    while(i<N1 && j<N2){
        if(vl1[i].first == vl2[j].first){
            ans += min(p+vl1[i].second,q+vl2[j].second) - max(p,q);
        }
        if(p+vl1[i].second < q+vl2[j].second){
            p+=vl1[i].second;
            i+=1;
        }
        else{
            q+=vl2[j].second;
            j+=1;
        }
    }
    
    
    cout << ans << endl;
}