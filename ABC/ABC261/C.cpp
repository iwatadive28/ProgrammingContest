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
    int N;
    cin >> N;
    vector<string> ans(N);
    map<string,int> mp; //key,cnt;
    
    rep(i,N){
        string s,tmp;
        cin >> s;
        if (mp.find(s) == mp.end()){
            mp[s] = 0;
        }else{
            mp[s]++;
        }

        if(mp[s]!=0){
            ans[i] = s + "(" + to_string(mp[s]) + ")";
        }else{
            ans[i] = s;
        }
        
    }

    rep(i,N){
        cout << ans[i] << endl;   
    }
    
}
