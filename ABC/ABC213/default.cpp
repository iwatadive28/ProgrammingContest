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
ll fmax(ll a,ll b){
    return (a>b?a:b);    
}

bool IsPrime(ll num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0) return false;// 素数ではない
    }
    return true; // 素数である
}

int main(){
    ll N;
    cin >> N;
    // cout << IsPrime(N) << endl;

    // 素数リスト作成
    vector<ll> prime;
    for(ll i=2;2*i*i*i<=N;++i){
        if(IsPrime(i)){
            prime.push_back(i);
        }
    }
    ll num_prm = prime.size();
    
    // p,q^3の配列作成
    vector<ll> p,q;
    for(ll i=0;i<num_prm-1;++i){
        p.push_back(prime[i]);
        q.push_back(prime[i+1]*prime[i+1]*prime[i+1]);
    }
    p.push_back(INF);
    
    // P*log(P)
    ll cnt = 0;
    for(ll i=0;i<num_prm-1;++i){
        ll k_p  = N/p[i]+1;
        ll iter = lower_bound(q.begin(),q.end(),k_p) - q.begin() - i;
        cnt += fmax(0,iter);
    }

    cout << cnt << endl;
}