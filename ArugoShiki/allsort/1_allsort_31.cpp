#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

bool is_prime(int x){
    bool is_prime = true;
    if (x==1){
        is_prime = false;
    }else{
        for(int i=2;i<x;++i){
            if (x%i==0){
                is_prime = false;
                break;
            }
        }
    }
    return is_prime;
}

int N;

int main() {
	cin >> N;
    
    int cnt = 0;
    rep(i,N){
        int A;
        cin >> A;
        if (is_prime(A)){
            // cout << A << ",Sosu" << endl;
            cnt++;
        }
    }    
    cout << cnt << endl;
    return 0;
}