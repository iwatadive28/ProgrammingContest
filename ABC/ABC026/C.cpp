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
// const ll INF = 1LL << 60;  //無限大
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    int N;
    cin >> N;
    vector<int> B(N,0); // 社員i の上司
    for(int i=1;i<N;i++){
        cin >> B[i];B[i]--;
    }
        
    vector<vector<int>> sub(N); // 社員i の部下リスト
    for(int i=1;i<N;i++){
        sub[B[i]].push_back(i);
        // printf("i=%d,sub[B[%d]]=%d\n",i,i,B[i]);
    }
    
    vector<int> P(N); // 社員i の給料 0は高橋君
    for(int i=N-1;i>=0;i--){
        // printf("sub[%d].size=%d\n",i,sub[i].size());
        if(sub[i].size()==0){
            P[i]=1;
            continue;
        }
        int maxP = 0;
        int minP = INF;
        for(auto j:sub[i]){
            maxP = max(maxP,P[j]);
            minP = min(minP,P[j]);
        }
        P[i] = maxP + minP + 1;
        // printf("i=%d,maxP=%d,minP=%d,P[%d]=%d\n",i,maxP,minP,i,P[i]);
    }

    cout << P[0] << endl;
}