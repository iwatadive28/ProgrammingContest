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
    cin >> N;
    vector<string> s(N),t(N);
    rep(i,N){
        cin >> s[i];
        cin >> t[i];
    }

    bool ans = true;
    rep(i,N){
        bool sames = false;
        string a = s[i];
        rep(j,N){
            if (i!=j){
                if (a == s[j]) sames = true;
                if (a == t[j]) sames = true;
            }
        }
        bool samet = false;
        
        a = t[i];
        rep(j,N){
            if (i!=j){
                if (a == s[j]) samet = true;
                if (a == t[j]) samet = true;
            }
        }
        if (sames & samet){
            ans = false;
        }    
    }

    cout << (ans?"Yes":"No") << endl;
}