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
    int n,w;
    cin >> n >> w;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> sum(w+1,false);

    // 全探索
    for(int i = 0;i<n;++i){
        int a1 = a[i];
        for(int j=0;j<n;++j){
            int a2 = a[j];
            if(i==j) a2 = 0;
            for(int k=0;k<n;++k){
                int a3 = a[k];
                if(i==k | j==k) a3 = 0;
                // cout << "a1,a2,a3= " <<a1 << ","<<a2<<","<<a3<<endl; 
                if (a1+a2+a3<=w){
                    sum[a1+a2+a3] = true;
                }                
            }
        }
    }

    // カウント
    int cnt = 0;
    rep(i,w+1){
        if(sum[i]) cnt++;
    }  

    cout << cnt << endl;    
}