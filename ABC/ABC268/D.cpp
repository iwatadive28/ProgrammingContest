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
vector<vector<int>> bar;
void dfs(vector<int> h,int n,int r){ // n個の_をr箱に入れる組み合わせ
    if(n<=0){
        bar.push_back(h);
        return;
    }
    rep(i,r){
        auto h1 = h;
        h1[i]++;
        dfs(h1,n-1,r);
    }
    return;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<string> S(N),T(M);
    rep(i,N) cin >> S[i];
    rep(i,M) cin >> T[i];
    sort(T.begin(),T.end());
    
    // 全列挙
    sort(S.begin(),S.end());
    vector<vector<string>> vec(0,vector<string>(N));
    do {
        vec.push_back(S);
    } while (next_permutation(S.begin(), S.end()));


    // 残りの文字数
    int remain = 16;
    rep(i,N) remain -= S[i].size();
    remain -= N-1;
    
    for(auto S1:vec){
        rep(k,remain+1){
            // "_"がどこにいくつ挿入されるか？ O((k+N-1−1)C(k))
            bar.assign(0,vector<int>(N,0));
            vector<int> h(N,0);
            dfs(h,k,N-1);

            for(auto bar1:bar){       
                /*cout << "remain = " << k << ",";
                for(auto b:bar1) cout << b << " ";
                cout << endl;*/
                
                // X生成
                string X;
                rep(j,N){
                    X += S1[j];
                    X += "_";
                    rep(b,bar1[j]) X += "_";
                }
                X.pop_back();
                
                // 判定
                bool ok = true;
                if(X.size()<3 || X.size()>16)          ok = false;
                if(binary_search(T.begin(),T.end(),X)) ok = false;
                
                // 出力
                if(ok){
                    cout << X << endl;
                    return 0;
                }
            }            
        }
    }
    
    cout << "-1" << endl;
}
