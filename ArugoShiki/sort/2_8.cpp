#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//
// 生徒情報
struct Menu {
    ll value;
    ll stock;
};

int main(){
    // INPUT
    ll N,K;
    cin >> N >> K;

    vector<Menu> M(N);
    rep(i,N) cin >> M[i].value >> M[i].stock;

    // コスト少ない順→在庫多い順に並べる
    // 同じところの順位を保つように、安定ソートを使う
    auto cmp = [&](Menu x, Menu y) -> bool {
        if (x.value < y.value){
            return true;
        }
        else if (x.value == y.value && x.stock > y.stock){
            return true;
        }
        else{
            return false;
        }
    };
    // SORT
    stable_sort(M.begin(), M.end(), cmp);

    // Kを超えるまで購入していく
    ll cost = 0;
    ll num  = 0;
    ll idx  = 0;
    rep(i,N){
        cost += M[i].value * M[i].stock;
        num  += M[i].stock;
        idx = i;
        if (num>=K) break;
    }

    // Kになるまで引き算する
    while(num>K){
        --num;
        cost -= M[idx].value;
        --M[idx].stock;
        if (M[idx].stock==0) --idx;
    }

    // Output
    cout << cost << endl;
    return 0;
}