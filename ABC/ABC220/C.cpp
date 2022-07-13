#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)

int main(){
    ll N,X;

    cin >> N;

    vector<ll> A(N);
    ll sumA = 0;

    rep(i,N){
        cin >> A[i];
        sumA += A[i];
    } 

    cin >> X;
    ll b = X/sumA;
    X -= b*sumA;

    ll cnt=0;
    rep(i,N){
        cnt ++; 
        if (A[i] > X){
            break;
        }        
        X-=A[i];       
    }       
    cout << b*N+cnt  << endl;    
}