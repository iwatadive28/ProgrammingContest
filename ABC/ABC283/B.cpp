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
int main(){
    int n,q;
    cin >> n;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    cin >> q;

    vector<ll> ans;
    rep(i,q){
        ll a,k,x;
        cin >> a >> k;
        k--;
        if(a==1){
            cin >> x;
            A[k] = x;
        }
        else if(a==2){
            ans.push_back(A[k]);
        }
    }
    for(auto a:ans){
        cout << a << endl;
    }
}
