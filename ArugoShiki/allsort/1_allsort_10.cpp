#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main() {
	int N;
	cin >> N;

	int cnt[9];
    rep(i,9){
        cnt[i] = 0;
    }

    rep(i,N){
        int A;
        cin >> A;
        cnt[A-1]++;
    }

    int cnt_mx=0;
    int ans;
    rep(i,9){
        if (cnt[i]>cnt_mx){
            cnt_mx = cnt[i];
            ans    = i+1;
        }
	}
    cout << ans << endl;
    return 0;
}