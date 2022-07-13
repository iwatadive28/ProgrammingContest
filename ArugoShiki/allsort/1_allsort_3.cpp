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
    int cnt = 0;
    rep(i,N){
        cin >> data[i];
        if (data[i] > 0){
            cnt++;
        }
    }
    
    cout << cnt  << endl;    
    
}