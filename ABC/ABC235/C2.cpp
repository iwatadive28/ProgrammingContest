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
    int n,q;
    cin >> n >> q;
    map<ll, vector<int>> mp;
    rep(i,n){
        ll a;
        cin >> a;
        mp[a].push_back(i+1);
    }

    rep(qi,q){
        int x,k;
        cin >> x >> k;
        vector<int>& p = mp[x]; // 参照すると、見やすくなる。
        if (p.size() < k) cout << -1 << endl;
        else cout << p[k-1] << endl;

        // if (mp[x].size() < k) cout << -1 << endl;
        // else cout << mp[x][k-1] << endl;
    }
}