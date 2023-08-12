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
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/
int solve(vector<int> idx){
    int rep = 0;
    int l,r;
    cin >> l >> r;
    l--;r--;
    // l以上の範囲で最小のインデックスを返す
    int iterl = lower_bound(idx.begin(),idx.end(),l) - idx.begin();
    int iterr = lower_bound(idx.begin(),idx.end(),r) - idx.begin();

    rep = iterr - iterl;
    return rep;
}

int main(){
    int N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> idx;
    rep(i,N-1){
        if(S[i]=='A'&&S[i+1]=='C') idx.push_back(i);
    }
    idx.push_back(INF);

    vector<int> ans(Q);
    rep(i,Q) ans[i] = solve(idx);
    
    rep(i,Q) cout << ans[i] << endl;
}
