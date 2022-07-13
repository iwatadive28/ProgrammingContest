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

	int cnt = 0;
    rep(i,N){
        if (N%(i+1)==0){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}