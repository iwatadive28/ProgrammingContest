#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int N,K;
int A[110];

int main() {
    
    cin >> N >> K;
    rep(i,N) cin >> A[i];
    
    int cnt = 0;
    for (int i=0;i<N-1;++i){
        for (int j=i+1;j<N;++j){
            if (A[i]+A[j] <= K){
                cnt++;
            }
        }
    }        
	
    cout << cnt << endl;
    return 0;
}