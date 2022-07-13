#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
int kaijo(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>>  A(2*N,vector<ll>(2*N-1,-1));
    map<pair<ll,ll>,ll> mp;
    
    // kaijo(2*N-1)
    
    rep(i,2*N-1){
        for(ll j=i+1;j<2*N;++j){
            pair<ll,ll> pr;
            pr = make_pair(i,j);
            
            ll a;
            cin >> a;
            mp[pr] = a;
        }        
    }

    rep(i,kaijo(2*N-1)){
        pair<ll,ll> pr;
        pr = make_pair(i,j);
            
            
    }
    cout << "Yes"<< endl;    
}