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
// const ll INF = 1LL << 60;  //無限大
const int INF = 2147483647;
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353; //998244353
/*
*/
int func_div2(ll x){
    int res = 0;
    while(x%2==0){
        x/=2;
        res++;        
    }
    return res;
}

int func_div3(ll x){
    int res = 0;
    while(x%3==0){
        x/=3;
        res++;        
    }
    return res;
}

ll mypow(ll x,ll y){
    ll res = 1;
    rep(i,y) res*=x;
    return res;
}

int main(){
    int N;
    cin >> N;
    
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    // 素因数分解
    
    vector<vector<int>> num(N,vector<int>(3,0));
    rep(i,N){
        num[i][0] = func_div2(a[i]);
        num[i][1] = func_div3(a[i]);
        num[i][2] = a[i]/(mypow(2,num[i][0])*mypow(3,num[i][1]));

        // cout << a[i] << ":" << num[i][0] << " " << num[i][1] << " " << num[i][2] << endl;
    }
    
    // 残った数が不一致なら-1
    for(int i=1;i<N;++i){
        if(num[0][2]!=num[i][2]){
            cout << -1 << endl;
            return 0;
        }
    }

    // 素因数の最小値で割る
    int mn2 = INF;
    rep(i,N) chmin(mn2,num[i][0]);
    int mn3 = INF;
    rep(i,N) chmin(mn3,num[i][1]);
    // cout << mn2 << " " << mn3 << endl;

    rep(i,N) num[i][0] -= mn2;
    rep(i,N) num[i][1] -= mn3;

    // rep(i,N) cout << a[i] << ":" << num[i][0] << " " << num[i][1] << " " << num[i][2] << endl;
    

    ll ans = 0;
    rep(i,N){
        ans += num[i][0] + num[i][1];
    }
    cout << ans << endl;
    
}
