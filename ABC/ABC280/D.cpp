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
const ll MOD = 1000000007; //10^9 + 7
/*
*/

// 素因数分解
vector<pair<ll,ll>> pfact(ll x){
    // O(sqrt(x))
    vector<pair<ll,ll>> res;
    ll n = x;
    for (ll i=2;i*i<=x;i++){
        ll a = 0;        
        while(n%i==0){
            a++;
            n/=i;
        }
        if(a>0) res.push_back({i,a});
        if(i>n) break;        
    }
    if(n!=1) res.push_back({n,1});
    return res;
}

ll kaijo(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}

ll mypow(ll x,ll y){
    ll res = 1;
    rep(i,y) res*=x;
    return res;
}

int main(){
    ll K;
    cin >> K;

    // Kの素因数分解をする // sqrt(N)
    vector<pair<ll,ll>> vec = pfact(K);
    // for(auto a:vec) cout << a.first << "^" << a.second << endl;
   
    // すべてのp^aがX!で割り切れるか確認する
    ll s = vec.size();
    ll ans = vec[s-1].first;
    // cout << s << endl;
    
    ll left  = vec[s-1].first;
    ll right = 2000000;
    while(right-left >1){
        ll mid = (right+left)/2;
        ll k = kaijo(mid);
        bool mod = true;
        rep(j,s){
            if(k%mypow(vec[j].first,vec[j].second)!=0) mod = false;
        }

        if(mod){
            right = mid;
            chmin(ans,mid);
        }else{
            left = mid;
        }
    }

    cout << ans << endl;
    //*/
}