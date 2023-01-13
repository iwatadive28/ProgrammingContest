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

ll modpow(ll a, ll b, ll m) {
	// a^b mod m を求める
	ll p=1, q=a;
	rep(i,30){
        if ((b&(1LL<<i))!=0) {
			p*=q; 
            p%=m;
		}
		q*=q; 
        q%=m;
    }
    return p;
}

ll Div(ll a, ll b, ll m) {
	// a÷b の mod m での逆元を求める
	return (a * modpow(b, m-2, m)) % m;
}

// 変数
long long mod = 1000000007;
long long N;
long long fact[200009];
long long factinv[200009];

void init() {
	fact[0] = 1;
	for (int i = 1; i<=200000; i++) fact[i]    = (1LL*i*fact[i-1]) % mod;
	for (int i = 0; i<=200000; i++) factinv[i] = Div(1, fact[i], mod);
}

ll ncr(int n, int r) {
	if (n< r || r<0) return 0;
	return (fact[n] * factinv[r] % mod) * factinv[n-r] % mod;
}

ll query(int K) {
	ll ret = 0;
	// 「N 個中何個選ぶか」を全探索
	// そもそも K が大きいと 1 個か 2 個しか選べないので、そこに着目する
	for (int i=1; i<=N/K+1; i++) {
		int s1 = N-(K-1)*(i-1);
		int s2 = i;
		ret += ncr(s1,s2);
		ret %= mod;
	}
	return ret;
}


int main(){
    cin >> N;
    init();
    rep(k,N){
        ll ans = query(k+1);
        cout << ans << endl;
    }
}   