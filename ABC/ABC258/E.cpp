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
    
    ll N,Q,X;
    cin >> N >> Q >> X;
    vector<ll> W(N);
    rep(i,N) cin >> W[i];
    
    const ll all = accumulate(begin(W), begin(W) + N, 0ll);
    X %= all;
    vector<ll> cnt;
    ll ii = 0;
    map<ll,ll> pii;
    while(1){
        if(pii.find(ii) == pii.end()){
            pii[ii]=pii.size();
        }else{
            break;
        }

        ll tmp_cnt = 0;
        ll w  = 0;
        while(w<X){
            w+=W[ii];
            ii++;
            ii%=N;
            tmp_cnt++;
        }
        cnt.push_back(tmp_cnt);
        
        // cout << w << "," << tmp_cnt << "," << ii << endl;                
    }
    
    // rep(i,cnt.size()) cout << cnt[i] << "\n";
    // cout << pii[ii] << "," << pii.size() << "\n";
    ll b = pii[ii];
    ll n = pii.size()- b;
   
    // cout << b << ","<< n << endl;
    
    vector<ll> cnt1,cnt2;
    rep(i,cnt.size()){
        if (i<b) cnt1.push_back(cnt[i]);
        else cnt2.push_back(cnt[i]); 
    }
    
    //rep(i,cnt1.size()) cout << cnt1[i] << ",";
    //cout << "\n";
    //rep(i,cnt2.size()) cout << cnt2[i] << ",";
    //cout << "\n";    
    
    vector<ll> ans;
    rep(i,Q){
        ll q;
        cin >> q;
        q--;
        ll a;
        ll idx;
        if (q<b){
            idx = q;
            a = cnt1[q];
        }else{
            idx = (q-b)%n;
            a = cnt2[idx];
        }     
        ans.push_back(a);
        // cout << idx <<","<<  a << endl;
    }
   
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
}
