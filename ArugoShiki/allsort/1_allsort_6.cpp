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

	int mx = 0;
    rep(i,N){
        int A;
        cin >> A;
        if (A>mx){
            mx = A;
        }
    }
        
    cout << mx << endl;
	return 0;
}