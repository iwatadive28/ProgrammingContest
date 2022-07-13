#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
int N;

int main(){
    
    cin >> N;
    ll H[N];
    rep(i,N){
        cin >> H[i];
    }

    int cH = H[0];
    for(int i=1;i<N;++i){
        if(cH < H[i]){
            cH = H[i];
        }else{
            break;
        }
    }
    cout << cH << endl;
    
}