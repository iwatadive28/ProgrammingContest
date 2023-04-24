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
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    ll N;
    string S;
    cin >> N >> S;
    
    vector<pair<ll,ll>> pr;
    bool l=true;
    ll cnt = 0;
    ll idxl = 0;
    rep(i,N){
        if(S[i]=='o'){
            cnt++;
            if(l){
                idxl=i;
                l = false;
            }
        }
        else{
            if(!l){
                pr.push_back({-cnt,idxl});
                cnt = 0;
                l = true;
            }
        }
        if(i==N-1&&S[i]=='o') pr.push_back({-cnt,idxl});
    }

    // for(auto p:pr) cout << p.first << ","<< p.second << endl;
    sort(pr.begin(),pr.end());

    ll ans = -1;
    for(auto p:pr){
        ll cnt = -p.first;
        ll idx = p.second;
        bool dango = false;
        if(idx>0 && S[idx-1]=='-') dango =true;
        if(idx+cnt<N && S[idx+cnt]=='-') dango =true;
        if(dango){
            ans = cnt;
            break;
        }
    }
    cout << ans << endl;

}