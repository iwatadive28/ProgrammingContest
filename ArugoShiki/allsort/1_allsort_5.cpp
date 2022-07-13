#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    int N;
    cin >> N;
    int data[N];
    rep(i,N){
        cin >> data[i];
    }

    int cnt = 0;
    for(int i=1;i<N;++i){
        if (data[i] > data[i-1]){
            cnt++;
        }
    }

    cout << cnt << endl;    
    
}