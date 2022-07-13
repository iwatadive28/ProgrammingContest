#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//
bool even(ll a){
    if (a%2==0) return true;
    else        return false;
}

int main(){
    // INPUT
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];    
    
    // SORT
    sort(a.begin(),a.end());
    // 浮動小数出力に対応する (小数点以下 2 桁まで出す)
    cout << fixed << setprecision(2);
    // 
    double ans;
    if (even(N)){
        ans = (a[N/2-1]+a[N/2])* 0.5;
    }
    else{
        ans = a[(N-1)/2];
    }
    printf("%.6f\n",ans);
    //cout << ans << endl;


    return 0;
}