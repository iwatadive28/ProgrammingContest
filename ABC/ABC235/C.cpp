#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int N,Q;

int main(){
    cin >> N >> Q;
    ll  A[N];
    pair<ll,int> A_idx[N];
    rep(i,N){
        cin>>A[i];
        A_idx[i] = make_pair(A[i],i+1);
    }
    sort(A_idx,A_idx+N);

    pair<pair<ll,int>,int> x_k_idx[Q];
    rep(i,Q) {
        ll x;
        int k;
        cin >> x >> k;
        x_k_idx[i] = make_pair(make_pair(x,k),i);
    }
    sort(x_k_idx,x_k_idx+Q);


    ll ans[Q];
    rep(i,Q) {
        ans[i]=-1;
    }

    int j = 0;
    rep(i,N){
        cout << A_idx[i].first << "," << x_k_idx[j].first.first << "," << x_k_idx[j].second << endl;
        if (A_idx[i].first == x_k_idx[j].first.first){
            ans[x_k_idx[j].second] = A_idx[i].second;
            ++j;
        }
    }

    rep(i,Q){
        cout << ans[i] << endl;
    }    
}