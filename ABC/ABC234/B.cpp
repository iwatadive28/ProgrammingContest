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
    int N;
    cin >> N;
    vector<int> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];
    
    double ans = -1.0;
    rep(i,N-1){
        for(int j=i+1;j<N;++j){
            int X = x[i]-x[j];
            int Y = y[i]-y[j];
            double len = sqrt(X*X+Y*Y);    
            ans = max(ans,len);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}