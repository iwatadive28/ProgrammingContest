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
    int N,X,Y;
    cin >> N >> X >> Y;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    int posX = -1;
    int posY = -1;
    int B    = -1;
  
    ll res = 0;
    rep(i,N){
        if(a[i] == X) posX = i;
        if(a[i] == Y) posY = i;
        if(a[i] < Y or X < a[i]) B = i;
        res += max(0, min(posX, posY) - B);
        // cout << i << ":" << res << "," << max(0, min(posX, posY) - B) << endl;
    }
    cout << res << endl;

}