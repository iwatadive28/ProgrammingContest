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
    int N,K;
    cin >> N >> K;
    vector<vector<int>> P(N,vector<int>(3));
    vector<int> PM(N,0);
    rep(i,N){
        rep(j,3){
            cin >> P[i][j];
            PM[i]+= P[i][j];
        }
    }
    vector<int> b = PM;
    sort(b.begin(),b.end());
    
    // rep(i,N) cout << PM[i] << ",";
    // cout << endl;

    rep(i,N){
        bool ans = false;
        int juni = b.end() - upper_bound(b.begin(),b.end(),PM[i]+300) + 1;
        if (juni <= K ) ans = true;
        // printf("i,juni,score=%d,%d,%d\n",(int)i,juni,PM[i]+300);
        cout << (ans?"Yes":"No") << endl;
    }
}