#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
int H,W;
int A[55][55];

int main(){
    cin >> H >> W;
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }

    bool ans = true;
    for (int i1=0 ; i1 < H-1; i1++){
        for (int i2=i1+1 ; i2 < H; i2++){
            for (int j1=0 ; j1 < W-1; j1++){
                for (int j2=j1+1 ; j2 < W; j2++){
                    // printf("i1=%d, i2=%d, j1=%d, j2=%d, A[i1][j1]+A[i2][j2]=%d, A[i2][j1]+A[i1][j2]=%d\n",i1,i2,j1,j2,A[i1][j1] + A[i2][j2],A[i2][j1] + A[i1][j2]);
                    if ( (A[i1][j1] + A[i2][j2]) > (A[i2][j1] + A[i1][j2])){
                        ans = false;
                        //break;
                    }
                }
            }
        }
    }
    if (ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}