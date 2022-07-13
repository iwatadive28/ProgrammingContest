#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//

 
int main() {
    int N;
    cin >> N;
    vector<int> cnt(N+1,0);
    
    //O(N-1)
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        ++cnt[a];
        ++cnt[b];
    }

    //O(logN+1)
    sort(cnt.begin(),cnt.end());
    bool ans = (cnt[N] == N-1);
    //cout << cnt[N] << endl;
    
    cout << (ans?"Yes":"No") << endl;
}