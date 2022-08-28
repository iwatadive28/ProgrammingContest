#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//

int main(){
    ll N,D;
    cin >> N >> D;
    vector<pair<ll,ll>> LR(N);
    rep(i,N){
        ll l,r;
        cin >> l >> r;
        LR[i]={r,l};
    }
    // O(NlogN)
    sort(LR.begin(),LR.end());

    // O(N)
    ll ans = 0;
    ll i = 0;
    while(i<N){ // パンチの回数ループ
        ll d = LR[i].first+D-1;   
        i++;
        while(i<N){ // 1発のパンチで壊す壁の数だけループ
            if(LR[i].second <= d ){
                i++;
            }else{
                break;
            }
        }
        ans++;
    }

    cout << ans << endl;    
}
