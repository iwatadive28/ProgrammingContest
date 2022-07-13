#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
int main(){
    ll X,A,D,N;
    cin >> X >> A >> D >> N;
    
    ll ans = 0;
    // 0項目以下 or 0項目以上
    if (D>=0 && X<=A){
        ans = A-X; 
    }     
    else if (D<0 && X>=A) {
        ans = X-A;
    }
    else if (D>=0 && X>=A+(N-1)*D){
        ans = X- (A+(N-1)*D);
        // cout << A+(N-1)*D << "," << X <<","<< ans << endl;
    }
    else if (D<0  && X<=A+(N-1)*D) {
        ans = (A+(N-1)*D)-X;
    }
    else{
        ll n = (X-A)/D;
        ans = min(abs(X-(A+n*D)),abs(X-(A+(n+1)*D)));
    }
    cout << ans << endl;
}
