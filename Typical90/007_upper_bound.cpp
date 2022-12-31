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
/*
*/
ll mymin(ll a,ll b){
    if(a>b) return b;
    else    return a;
}
int N, Q, A[300010];
int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);
    cin >> Q;
    vector<int> ans;
    for (int i = 0; i < Q; i++) {
        int B;
        cin >> B;
        int tmp = INF;
        auto p = upper_bound(A, A + N, B);
        if (p != A + N) tmp = min(tmp, *p - B);
        if (p != A)     tmp = min(tmp, B - *prev(p));
        ans.push_back(tmp);
    }

    for(auto x:ans) cout << x << endl;
    return 0;
}