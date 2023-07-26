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
    int N;
    cin >> N;
    vector<ll> A(N,0);
    rep(i,N){
        cin >> A[i];
        A[i]--;
    }

    vector<int> s;
    vector<bool> fl(N,false);
    int v = 0;
    while(!fl[v]){
        fl[v]=true;
        s.push_back(v);
        v=A[v];
    }

    vector<int> ans;
    for(auto &nx:s){
        if(nx==v) v=-1;
        if(v==-1){
            ans.push_back(nx);
        }
    }

    cout << ans.size() << endl;
    for(auto a:ans) cout << a+1 << " ";
    cout << endl;
}