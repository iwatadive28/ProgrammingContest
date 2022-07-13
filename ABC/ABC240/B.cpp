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
    ll N;
    cin >> N;
    set<ll> st;
    rep(i,N){
       ll a;
       cin >> a;
       if(!st.count(a)){
           st.insert(a); 
       }       
    }
    
    cout << st.size() << endl;
}