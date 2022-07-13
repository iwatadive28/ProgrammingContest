#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(2*N,vector<ll>(2*N,-1));
    
    rep(i,2*N-1){
        for(ll j=i+1;j<2*N;++j){
            // cin >> A[i][j];
            cout << i << ',' << j << endl;
        }
    }
    //string S[N];

    cout << "Yes"<< endl;    
}