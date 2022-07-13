#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int N;
int A[110];

int main() {
    
    cin >> N ;
    rep(i,N) cin >> A[i];
    
    int cnt = 0;
    for (int x=0;x<N-2;++x){
        for (int y=x+1;y<N-1;++y){
            for (int z=y+1;z<N;++z){
                if (A[y] >= A[x] && A[y] >= A[z]){
                    // printf("(x,y,z)=(%d,%d,%d)\n",x,y,z);
                    cnt++;
                }
            }
        }
    }

	
    cout << cnt << endl;
    return 0;
}