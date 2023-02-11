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
// セグメント木
/*
区間に対する処理を(logW)で実行可能
- 最大値、最小値、合計を求める
- 更新する、加算する
//*/
class segment_tree {
private:
	int sz;
	std::vector<int> seg;
	std::vector<int> lazy;
	void push(int k) {
		if (k < sz) {
			lazy[k * 2] = max(lazy[k * 2], lazy[k]);
			lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
		}
		seg[k] = max(seg[k], lazy[k]);
		lazy[k] = 0;
	}
	void update(int a, int b, int x, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			push(k);
			return;
		}
		update(a, b, x, k * 2, l, (l + r) >> 1);
		update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
		seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
	}
	int range_max(int a, int b, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return seg[k];
		int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
		int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
		return max(lc, rc);
	}
public:
	segment_tree() : sz(0), seg(), lazy() {};
	segment_tree(int N) {
		sz = 1;
		while (sz < N) {
			sz *= 2;
		}
		seg = std::vector<int>(sz * 2, 0);
		lazy = std::vector<int>(sz * 2, 0);
	}
	void update(int l, int r, int x) {
		update(l, r, x, 1, 0, sz);
	}
	int range_max(int l, int r) {
		return range_max(l, r, 1, 0, sz);
	}
};


int main(){
    ll W,N;
    cin >> W >> N;
    segment_tree seg(W);
    vector<ll> ans(N,0);
    rep(i,N){
        ll l,r;
        cin >> l >> r;
        ll highest = seg.range_max(l-1,r)+1;
        seg.update(l-1,r,highest);
        ans[i] = highest;
    }

    rep(i,N) cout << ans[i] << endl;    
}
