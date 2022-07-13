#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int N,M,K;
int A[110],B[110];

int main() {
    
    cin >> N >> M >> K;
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];
    
    int cnt = 0;
    rep(i,N){
        rep(j,M){
            if (A[i]+B[j]==K){
                cnt++;
            } 
        }
    }
	
    cout << cnt << endl;
    return 0;
}