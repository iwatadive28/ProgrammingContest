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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];
    sort(A.begin(),A.end());

    set<ll> st;
    vector<vector<ll>>  d(N,vector<ll>(N,0));

    while(st.size()<10*K){
        ll mn = INF;
        rep(i,N){
            rep(j,N){
                if(A[i]+d[i][j]<mn){
                    mn = A[i]+d[i][j];
                    d[i][j]=A[i]+d[i][j];
                }
            }
        }
        if(!st.count(mn)){
           st.insert(mn); 
        }  
    }

    vector<ll> p;
    for(auto itr = st.begin(); itr != st.end(); ++itr) {
        p.push_back(*itr);      // イテレータの指す先のデータを表示
    }

    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    for(auto a:p) cout << a <<" ";
    cout << endl;

    cout << p[K-1] << endl;    
}