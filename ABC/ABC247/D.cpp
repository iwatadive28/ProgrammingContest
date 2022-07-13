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
queue<pair<ll,ll>> q; // 数と個数のペアを保存

ll ope_1(ll x,ll c){
    pair<ll,ll> pr = make_pair(x,c);
    q.push(pr);
    return 0;
}

ll remain = 0;

ll ope_2(ll c){
    ll sum=0;
    pair<ll,ll> pr = q.front();

    while(c>0){
        ll cnt;
        if (remain == 0){
            cnt = pr.second;
        }
        else{
            cnt = remain;
        }

        if (c < cnt){
            sum += pr.first * c;
            remain = cnt-c;
            c=0;
        }
        else{
            sum += pr.first * cnt;
            c -= cnt;

            q.pop();
            pr = q.front();
            remain = 0;
        }
        // cout << "tmp:sum,remain=" << sum <<","<< remain << endl;
    }
    
    cout << sum <<endl;
    return sum;
}

int main(){
    ll Q;
    cin >> Q;

    vector<int> ope(Q);
    vector<ll> x(Q,0),c(Q);

    rep(i,Q){
        cin >> ope[i];
        if (ope[i]==1) cin >> x[i] >> c[i];
        else           cin >> c[i];
    }

    rep(i,Q){
        if (ope[i]==1){
            ope_1(x[i],c[i]);
        }

        else{
            ope_2(c[i]);
        }
    }
}