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
    int N;
    vector<ll> P(3);
    cin >> N >> P[0] >> P[1] >> P[2];
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> sum(N+1,0);
    rep(i,N) sum[i+1] += sum[i]+A[i];
    
    // rep(i,N+1) cout << sum[i] << " ";
    // cout << endl;

    bool ans = false;
    for(ll i=0;i<N-2;++i){
        ll tx = sum[i];
        ll k = 0;
        
        // x[i]以上の範囲で最小のインデックスを返す
        rep(k,3){
            ll iter = lower_bound(sum.begin(),sum.end(),P[k]+tx) - sum.begin();
            if(sum[iter]-tx == P[k]){
                tx = sum[iter];
                if(k==2) {
                    ans = true;
                    break;
                }
            }else{
                break;
            }
            if(ans) break;
        }
    }

    cout << (ans?"Yes":"No") << endl;
}
