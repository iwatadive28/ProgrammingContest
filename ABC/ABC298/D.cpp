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
const ll MOD = 998244353; //10^9 + 7
const double pi = 3.14159265358979;

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
/*
*/
ll mypow(ll x,ll y){
    ll res = 1;
    rep(i,y){
        res*=x;
        res%=MOD;
    }
    return res;
}

int main(){
    ll Q;
    cin >> Q;
    
    deque<int> S(1,1);
    vector<int> ans;
    mint val = 1;

    rep(q,Q){
        int x;
        cin >> x;
        if(x==1){
            int y;
            cin >> y;
            S.push_back(y);
            val = val*10+y;
            
        }
        if(x==2){
            val -= mint(10).pow(S.size()-1) * S.front();
            S.pop_front();
        }
        if(x==3){
            // cout<< val.val() <<endl;
            ans.push_back(val.val());                
        }
    }
    for(auto a:ans) cout << a << endl;
}