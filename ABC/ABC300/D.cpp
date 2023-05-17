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
#define MAXP 300005

// エラトステネスの篩（ふるい）
// 素因数を列挙
vector<ll> sieve(){
    vector<ll> res;
    vector<bool> mem(MAXP,false);
    for (ll i=2; i<MAXP; i++){
        if(mem[i]) continue;
        res.push_back(i);
        for (ll j=i; j<MAXP; j+=i) mem[j]=true;
    }
    return res;
}

int main(){
    vector<ll> P = sieve();
    ll N;
    cin >> N;
    
    int sz = P.size();
    int res = 0;
    
    for (ll i=0; i<sz; i++){
        int k = sz-1;
        for (ll j=i+1; j<k && j<sz; j++){
            while(j<k){
                ll v = P[i]*P[i]*P[j];
                if(v>N){k--;continue;}
                v*=P[k];
                if(v>N){k--;continue;}
                v*=P[k];
                if(v>N){k--;continue;}
                break;
            }
            res+=(k-j);
        }
    }
    //*/
    cout << res << endl;
}