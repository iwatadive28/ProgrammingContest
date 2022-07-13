#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    ll N,M;
    cin >> N >> M;
    string S[N];

    rep(i,N) cin >> S[i];
    
    set<string> st;
    rep(i,M){
        string t;
        cin >> t;
        st.insert(t);
    }

    //
    rep(i,N){
        cout << (st.count(S[i]) ? "Yes":"No" )<< endl;
        // cout << (st.find(S[i]) ? "Yes":"No" )<< endl;
    }
    
}