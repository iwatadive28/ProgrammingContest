#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/
int k;
multiset<int> x,y; // xは大きい方からk個の値,yはそれ以外の値
ll sum;

void balance(){
    while(x.size()<k){  // xがk未満の時
        auto iy=y.end();iy--;// yの最大値をxに追加
        x.insert(*iy);
        sum += (*iy);
        y.erase(iy);
    }
    if(x.empty()|| y.empty()) {return;}
    while(1){
        auto ix = x.begin();    // 最小値
        auto iy = y.end();iy--; // 最大値
        int ex = (*ix);
        int ey = (*iy);

        if(ex>=ey) break;
        // eyのほうが大きかったら置き換える
        sum += (ey-ex);
        x.erase(ix);
        y.erase(iy);
        x.insert(ey);
        y.insert(ex);
    }

}

// y に特定の値vを追加した上で balance する。
void add(int v){
    y.insert(v);
    balance();
}

// 特定の値vをxまたはyから削除する。その後balanceする。
void erase(int v){ 
    auto ix=x.find(v);
    if(ix!=x.end()){ // vがxに含まれる場合
        sum -= v;
        x.erase(ix);
    }else{
        y.erase(y.find(v)); 
    }
    balance();
}

int main(){
    int n;
    cin >> n >> k;
    vector<ll> a(n,0);
    for(int i=0;i<k;i++) x.insert(a[i]);
    for(int i=k;i<n;i++) y.insert(a[i]);
    sum = 0;

    int q;
    cin >> q;
    vector<ll> P(q),W(q);
    rep(i,q) cin >> P[i] >> W[i];

    vector<ll> ans;
    rep(i,q){
        int p = P[i];
        int w = W[i];
        p--;
        add(w);
        erase(a[p]);
        a[p]=w;
        ans.push_back(sum);
    }

    for(auto a:ans) cout << a << endl;

}