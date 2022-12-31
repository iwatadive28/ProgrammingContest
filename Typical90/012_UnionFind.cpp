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

// Union-Find
struct UnionFind{
    vector<int> par,siz;
    // 初期化
    UnionFind(int n):par(n,-1),siz(n,1){ }
    
    // 根を求める
    int root(int x){
        if(par[x]==-1) return x; // xの場合はxを返す
        else return par[x] = root(par[x]); // 再帰的にxの親の根を返す
    }

    // xとyが同じグループに属するかどうか(根が一致するかどうか)
    bool issame(int x,int y){
        return root(x)==root(y);
    }

    // xを含むグループとyを含むグループとを併合する
    bool unite(int x,int y){
        // x,yをそれぞれ根まで移動する
        x = root(x);
        y = root(y);

        // すでに同じグループの時は何もせず
        if(x == y) return false;

        // union by size (y側のサイズが小さくなるようにする)
        if(siz[x]<siz[y]) swap(x,y);

        // yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // xを含むグループのサイズ
    int size(int x){
        return siz[root(x)];
    }
};

int dx[4] = {-1, 0, 1, 0}; // 下、右、上、左 をあらかじめ作成
int dy[4] = { 0, 1, 0,-1};

int main(){
    int H,W,Q;
    cin >> H >> W >> Q;
    
    vector<string> Ans;
    // 例外判定をしないように配列を±1広めに作成
    vector<vector<bool>>  used(H+2,vector<bool>(W+2,false));
    UnionFind uf(H*W); // マスの数(H*W)だけ宣言,pairではなく優位なhash値で扱う

    rep(i,Q){
        int q;
        cin >> q;
        if(q==1){ // query1
            int x,y;
            cin >> x >> y;
            used[x][y] = true;
            rep(i,4){
                int sx = x+dx[i];
                int sy = y+dy[i];
                if(used[sx][sy]==false) continue;
                int hash1 = (x-1) *W +(y-1);
                int hash2 = (sx-1)*W+(sy-1);
                uf.unite(hash1,hash2);
            }
        }else{ // query2
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            bool ans = false;
            if( !used[x1][y1] || !used[x2][y2]) ans = false;
            else{
                int hash1 = (x1-1)*W +(y1-1);
                int hash2 = (x2-1)*W +(y2-1);
                ans = uf.issame(hash1,hash2);
            }
            Ans.push_back(ans?"Yes":"No");
        }
    }
    
    for(auto ans:Ans) cout << ans << endl;
}   