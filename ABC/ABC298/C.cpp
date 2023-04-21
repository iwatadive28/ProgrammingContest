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
    int N,Q;
    cin >> N >> Q;

    vector<map<int,int>> box(200005); // 箱、カード、枚数
    vector<set<int>> num(200005); // nが入っている箱
    vector<vector<int>> ans; 
    
    rep(q,Q){
        int x;
        cin >> x;
        if(x==1){
            int i,j;
            cin >> i >> j;
            box[j][i]++;
            num[i].insert(j);
        }else if (x==2){
            int i;
            cin >> i;
            vector<int> tmp;
            for (auto itr = box[i].begin();itr != box[i].end() ; itr++ ){
                rep(k,itr->second) tmp.push_back(itr->first);
            }
            ans.push_back(tmp);
        }else{
            int i;
            cin >> i;
            vector<int> tmp;
            for(auto a:num[i]) tmp.push_back(a);     // 要素を順に表示
            ans.push_back(tmp);
        }
    }

    for(auto vc:ans){
        for(auto a:vc){
            cout << a << " ";
        }
        cout << endl;
    }
}