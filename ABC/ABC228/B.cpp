#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    int N,X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    
    vector<bool> kw(N,false);
    int ans = 0;
    int next = X-1;
    while(true){
        if (kw[next]) break;
        kw[next] = true;
        next = A[next]-1;
        ++ans;        
    }

    cout << ans << endl;
   
    
}