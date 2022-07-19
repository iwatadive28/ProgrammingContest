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
    int N,X,Y,Z;
    cin >> N >> X >> Y >> Z;
    vector<int> A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    
    vector<pair<int,int>> Ai(N),Bi(N),Si(N);
    rep(i,N){
        Ai[i] = {-A[i],i+1};
        Bi[i] = {-B[i],i+1};
        Si[i] = {-A[i]-B[i],i+1};            
    }
    sort(Ai.begin(),Ai.end());
    sort(Bi.begin(),Bi.end());
    sort(Si.begin(),Si.end());

    set<int> st;
    vector<int> ans;
    int i=0;
    int j=0;
    while(i<X){
        // cout << Ai[i].second << endl;
        st.insert(Ai[i].second);
        ans.push_back(Ai[i].second);
        i++;
    }

    i=0;
    while(j<Y){
        if(st.count(Bi[i].second)) {
            i++;
            continue;
        }
        // cout <<  Bi[i].second << endl;
        st.insert(Bi[i].second);
        ans.push_back(Bi[i].second);
        i++;
        j++;
    }

    i=0;
    j=0;
    while(j<Z){
        if(st.count(Si[i].second)){
            i++;
            continue;
        }
        // cout << Si[i].second << endl;
        st.insert(Si[i].second);
        ans.push_back(Si[i].second);
        i++;
        j++;
    }
    
    sort(ans.begin(),ans.end());
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
}
