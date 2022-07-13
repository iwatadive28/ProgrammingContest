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
    vector<int> S(N);
    rep(i,N) cin >> S[i];
    
    set<int> st;
    for(int a=1;a<=1000;++a){
        for(int b=1;b<=1000;++b){
            int tmp = 3*a + 4*a*b + 3*b;
            if (tmp>1000) break;
            if(!st.count(tmp)) st.insert(tmp); 
        }
    }

    int ans = 0;
    rep(i,N){
        if(!st.count(S[i])) ans++;
    }
    cout << ans << endl;
}