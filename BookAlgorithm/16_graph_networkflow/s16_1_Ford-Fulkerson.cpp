#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
// using Graph = vector<vector<int>>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
// グラフを表す構造体
struct Graph{
    // 辺を表す構造体
    // rev: 逆辺(to,from)がG[to]の中で何番目か？
    // cap: 辺(to,from) の容量
    struct Edge{
        int rev,from,to,cap;
        Edge(int r,int f,int t,int c):
            rev(r),from(f),to(t),cap(c){}
    };

    // 隣接リスト
    vector<vector<Edge>> list;

    // N:頂点数
    Graph(int N=0) : list(N){}

    // グラフの頂点数取得
    size_t size(){
        return list.size();
    }

    // GraphインスタンスをGとして
    // G.list[v] を G[v] と書けるようにしておく
    vector<Edge> &operator [] (int i){
        return list[i];
    }

    // 辺 e=(u,v) の逆辺(v,u) を取得する
    Edge& redge(const Edge &e){
        return list[e.to][e.rev];
    }

    // 辺 e=(u,v) に流量f のフローを流す
    void run_flow(Edge &e,int f){
        e.cap -= f;
        redge(e).cap += f;
    }

    // 頂点from から頂点to へ容量cap の辺を張る
    // このときto からfrom へも容量0 の辺を張っておく
    void addedge(int from,int to,int cap){
        int fromrev = (int)list[from].size();
        int torev   = (int)list[to].size();
        list[from].push_back(Edge(torev,from,to,cap));
        list[to].push_back(Edge(fromrev,to,from,0));
    }
};

struct FordFulkerson{
    static const int INF = 1 << 30; // 無限大を表す値を適切に
    vector<int> seen;

    FordFulkerson(){ }

    // 残余グラフ上でs-tパスを見つける(深さ優先探索)
    // 返り値はs-tパス上の容量の最小値(見つからなかったら0)
    // f:sからvへ到達した過程の各辺の容量の容量の最小値
    int fodfs(Graph &G,int v,int t,int f){
        // 終端t に達したらリターン
        if(v==t) return f;

        // 深さ優先探索
        seen[v] = true;
        for(auto &e:G[v]){
            if(seen[e.to]) continue;

            // 容量0 の辺は実際には存在しない
            if (e.cap==0) continue;

            // s-tパスを探す
            // 見つかったらflowはパス上の最小容量
            // 見つからなかったらf=0
            int flow = fodfs(G,e.to,t,min(f,e.cap));

            // s-tパスが見つからなかったら次の辺を試す
            if (flow==0) continue;

            // 辺e に容量flowのフローを流す
            G.run_flow(e,flow);

            // s-t パスを見つけたらパス上の最小容量を返す
            return flow;
        }

        // s-t パスが見つからなかったことを示す
        return 0;
    }

    // グラフG のs-t 間の最大流量を求める
    // ただし、リターン時にG は残余グラフになる
    int solve(Graph &G,int s,int t){
        int res = 0;
        // 残余グラフにs-t パスが無くなるまで反復
        while(true){
            seen.assign((int)G.size(),0);
            int flow = fodfs(G,s,t,INF);

            // s-t パスが見つからなかったら終了
            if (flow==0) return res;

            // 答えを加算
            res += flow;
        }

        // no reach
        return 0;
    }
};

int main (){
    // グラフの入力
    int N,M;
    cin >> N >> M;
    Graph G(N);
    rep(i,M){
        int u,v,c;
        cin >> u >> v >> c;
        // 容量c の辺(u,v) を張る
        G.addedge(u,v,c);
    }

    // フォード・ファルカーソン法
    FordFulkerson ff;
    int s = 0,t=N-1;
    cout << ff.solve(G,s,t) << endl;
}

