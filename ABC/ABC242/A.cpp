#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    double A,B,C,X;
    cin >> A >> B >> C >> X;
        
    double ans=0.000001;
    if (X<=A){
        ans = 1;
    }
    else if(X<=B){
        ans = C/(B-A);
    }else{
        ans = 0;
    }

    printf("%.12f\n",ans);
    
}