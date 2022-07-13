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
    
    int N;
    string S;

    cin >> N;
    cin >> S;

    // i 番目の操作が終わった時点で 
    // i より左側の要素からなる数列を L、
    // i より右側の要素からなる数列を R とします
    vector<ll> L;
    vector<ll> R;
    
    rep(i,N){
        if (S[i]=='R') L.push_back(i);
        else           R.push_back(i);
        
    }
    // 出力
    rep(i,L.size()) cout << L[i] << " "; 
    cout << N << " ";
    rep(i,R.size()) cout << R[R.size()-i-1] <<" ";
    cout << endl;

    return 0;
}