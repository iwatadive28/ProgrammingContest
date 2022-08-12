---
marp: true
theme: default   
header: "**アルゴリズムとデータ構造輪講 2022** __技術チャレンジ部__"
footer: "by iwasa.kenta"
---
<!--
_color: white
_footer: 'Photo by https://www.pakutaso.com/'
-->
<!-- paginate: true -->

![bg brightness:0.6](img/cat_pc.jpg.webp)
# アルゴリズムとデータ構造<br>13章 グラフ(1)：グラフ探索<!-- omit in toc -->

---
![bg right:40% 80% ](img/book.jpg)

# 目次 <!-- omit in toc -->

- [なぜグラフ探索を学ぶのか？](#なぜグラフ探索を学ぶのか)
- [深さ優先探索と幅優先探索](#深さ優先探索と幅優先探索)
  - [グラフ探索手法の代表](#グラフ探索手法の代表)
  - [グラフ探索で用いるデータ構造](#グラフ探索で用いるデータ構造)
  - [グラフ探索の実装](#グラフ探索の実装)
  - [木の場合の探索順](#木の場合の探索順)
- [再帰関数を用いる深さ優先探索](#再帰関数を用いる深さ優先探索)
- [「行きがけ順」と「帰りがけ順」](#行きがけ順と帰りがけ順)
  - [行きがけ順(pre-order)](#行きがけ順pre-order)
  - [帰りがけ順(post-order)](#帰りがけ順post-order)
- [最短路アルゴリズムとしての幅優先探索](#最短路アルゴリズムとしての幅優先探索)
- [深さ優先探索と幅優先探索の計算量](#深さ優先探索と幅優先探索の計算量)
- [グラフ探索例(1)：s-tパスを求める](#グラフ探索例1s-tパスを求める)
- [グラフ探索例(2)：二部グラフ判定](#グラフ探索例2二部グラフ判定)
- [グラフ探索例(3)：トポロジカルソート](#グラフ探索例3トポロジカルソート)
- [グラフ探索例(3)：木上の動的計画法](#グラフ探索例3木上の動的計画法)
- [まとめ](#まとめ)

---
# なぜグラフ探索を学ぶのか？
グラフ探索技法を身に着けると、単にグラフに関する問題を解決できるようになるだけでなく、様々な対象物に対する探索を見通し良く扱えるようになります。

**一見グラフとは関係ないように思える問題も、グラフ上の探索問題としてとらえ直すことができます。** グラフ探索技法に習熟すると、

- ウォール、サイクル、パス
- 連結性

なども、自税に扱えるようになります。
    
---
# 深さ優先探索と幅優先探索

## グラフ探索手法の代表

- 深さ優先探索（depth-first search：DFS）
- 幅優先探索（breadth-first search：BFS）

---

一例として、ネットサーフィンするときのことを思い浮かべる。下図のようなグラフはWeb ページのリンク関係を表す。グラフ探索の始点 s∈V は最初に開く Web ページであり、ここでは s=0 とする。
![imag](img/graph_1.png)

--- 
まず、 2 と 4 を保留にして 1 に対応するページを一通り読む(下図のように読了済のノードは赤く示す)。この次にどのページを読むのか？:

1. たった今読了した頂点 1 からそのまま辿れる頂点 (3 か 8) へと突き進む →**深さ優先探索**
2. 一旦、保留にしていた頂点 2, 4 に対応するページを読んでおく → **幅優先探索**

![imag](img/graph_2.png)

---

## グラフ探索で用いるデータ構造

グラフ探索では2つのデータで管理する。

|変数名|データ型(C++) |説明| 
|-|-|-| 
|seen |vector<bool>         |その頂点を検知済みかどうかを表す配列。<br>`seen[v]=true`の場合、頂点vがtodoに挿入された瞬間があったことを表している。すでにtodoから取り出されている場合も含む。| 
|todo |stack<int><br>queue<int>|検知したがまだ訪問済みでない頂点の集合 (保留中の頂点の集合)。これから訪問する予定の頂点。| 

---

|色|状態|seen|todo|
|-|-|-|-|
|白|探索においてまだ見つかっていない状態。todoにも挿入されていない。|seen[v]=false|vはtodoに含まれない|
|橙|探索済みであるが、未訪問の状態|senn[v]=true|v∈todo|
|赤|訪問済みの状態|senn[v]=true|vはtodoに含まれない|

---
## グラフ探索の実装

1. seen 全体を false に初期化して、todo を空にする
2. seen[s] = true として、todo に s を追加する 
3. todo が空になるまで以下を繰り返す:
    1. todo から一つ頂点を取り出してvとする
    2. G(v) の各要素xに対して、
        seen[x] = true であったならば、何もしない
        そうでなかったら、seen[x]=true として、todo にxを追加する

---
```c++
// グラフGにおいて、頂点sを始点とした探索を行う
void search(cnost Graph &G, int s){
    int N = (int)G.size(); // グラフの頂点数    
    // グラフ探索のためのデータ構造
    vector<bool> seen(N,false); // すべて未発見の状態
    queue<int>   todo;          // 空の状態(深さ優先探索では stack<int>)

    // 初期条件
    seen[s] = true; // sは探索済みとする
    todo.push(s);   // todoはsのみ含む状態とする

    while(!todo.empty()){ // todoが空になるまで探索を行う
        int v = todo.front(); // todoから頂点を取り出す
        todo.pop();

        for(int x:G[v]){  // vから辿れる頂点をすべて調べる
            if(seen[x]) continue; // すでに発見済みの頂点は探索しない
            seen[x] = true;       // 新たな頂点xを探索済み
            todo.push(x);         // todoに挿入
        }
    }
}
```
---

このコードは深さ優先探索？幅優先探索？

---

集合todo から頂点vを取り出す作業を行うときに、どのようなポリシーに従ってvを選ぶかによって、深さ優先探索か幅優先探索かの違いが生じる。

深さ優先探索：todoをスタックにすると、辿れる頂点を猪突猛進に探索する
幅優先探索：todoをキューにすると、todoに加えた頂点を順に一通り読んでから、より深いところへ進んでいく幅優先探索となる。
```c++
// グラフ探索のためのデータ構造
vector<bool> seen(N,false); // すべて未発見の状態
queue<int>   todo;          // 空の状態(深さ優先探索では stack<int>)
```
よって、上記コードは幅優先探索の例です。

---
## 木の場合の探索順

木：「**サイクルを持たない**」かつ「**連結**」であるようなグラフ。DFSとBFSの探索する順番の違いが分かりやすい。

![image](img/graph_tree.png)

---
# 再帰関数を用いる深さ優先探索

ここまで、seenとtodoというデータを用いた実装について説明していた。
DFSは再帰関数と相性がよく、組み込み系でない限りは、しばしば再帰関数を用いて実装されます。

---
```c++
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v){
    seen[v] = true; // vを訪問済みとする
    for(auto next_v:G[v]){
        if(seen[next_v]) continue; // next_vが訪問済みならスルー
        dfs(G,next_v); // 再帰的に探索
    }
}
int main(){
    int N,M; // 頂点数:N,辺数:M
    cin >> N >> M;
    // グラフの入力受取（ここでは有向グラフ）
    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        // G[b].push_back(a); // 無向グラフの場合、逆も挿入
    }
    // 頂点0からスタートした探索
    seen.assign(N,false); // 初期状態では全頂点が未訪問
    dfs(G,0); 
}
```
---
# 「行きがけ順」と「帰りがけ順」

深さ優先探索の探索順序について考える。「トポロジカルソート」や「木上の動的計画法」を学ぶ時の理解の助けになる。
ここで、探索順序は
- 頂点vがtodoから取り出されるタイミング
- 再帰関数dfs(G,v)が呼び出されるタイミング

となる。

---
## 行きがけ順(pre-order)
根から初めて訪問した頂点の順序で順位をつけたもの。
vの子孫となる頂点は、すべてvよりも後で登場する。

## 帰りがけ順(post-order)
最後に訪問した頂点の順序で順位をつけたもの。
vの子孫となる頂点は、すべてvよりも前で登場する。

![bg 70% fit vertical right](img/graph_ikigake.png)
![bg 70% fit vertical right](img/graph_kaerigake.png)

---
# 最短路アルゴリズムとしての幅優先探索
幅優先探索は、探索の始点となる頂点sから、各頂点への最短路を求めるアルゴリズムとも見なせる。データはseen, todo に対応するように、dist, queを用いる。

1. dist 全体を -1 に初期化して、que を空にする
2. dist[s] = 0 として、que に s を追加する 
3. que が空になるまで以下を繰り返す:
    1. que から一つ頂点を取り出して v とする
    2. G(v) の各要素xに対して、
        dist[x] != -1 であったならば、何もしない
        そうでなかったら、dist[x] = dist[v]+1 として、que にxを追加する

---
```c++
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
using Graph = vector<vector<int>>;

// 入力：グラフGと、探索の始点s
// 出力：sから各頂点への最短路長を表す配列
vector<int> BFS(cnost Graph &G, int s){
    int N = (int)G.size();  // 頂点数
    vector<int> dist(N,-1); // -1=未訪問に初期化
    queue<int> que;

    // 初期条件（頂点0を書記長店とする）
    dist[s] = 0;
    que.push(s); // 0を未訪問, queに加える

    // BFS開始（queが空になるまで探索を行う）
    while(!que.empty()){
        int v = que.front(); // queから先頭頂点を取り出す
        que.pop();

        // vから辿れる頂点をすべて調べる
        for(auto x:G[v]){
            if(dist[x] != -1) continue; // 発見済みの頂点は探索しない
            dist[x] = dist[v]+1; // 距離情報を更新
            que.push(x);         // queに挿入
        }
    }
    return dist;
}
```
---

```c++
int main(){
    int N,M // 頂点数:N, 変数:M
    cin >> N >> M;

    // グラフ入力受取(無向グラフを想定)
    Graph(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点0を始点としたBFS
    vector<int> dist = BFS(G,0);
    
    // 結果出力(各頂点の頂点0からの距離を見る)
    rep(v,N) cout << v << ":" << dist[v] << endl;
}
```

---
# 深さ優先探索と幅優先探索の計算量
グラフ G=(V,E) として、頂点数 |V| 、変数 |E| の２つを入力サイズとする。
深さ優先探索も、幅優先探索も、

- すべての頂点が、高々1回ずつ探索される：O(|V|)
- すべての辺が、高々1回ずつ探索される：O(|E|)

つまり、計算量は **O(|V|+|E|)** となる。つまり、グラフを入力として受け取るのと同等の時間でグラフ探索も実施できる。

---
# グラフ探索例(1)：s-tパスを求める
有向グラフ G の二頂点 s,t∈V が与えられたとき、s から辺をたどって t に到達できるかどうかを判定する問題。

単純に、s を始点としたDFSを実施する。DFS実施後に seen 配列を見ることで、各頂点が探索されたかどうかを判定することができる。

---
```c++
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(Graph &G,int v){
    seen[v] = true;
    for(auto next_v:G[v]){
        if(seen[next_v]) continue;
        dfs(G,next);
    }
}
int main(){
    int N,M,s,t // 頂点数、変数、スタート、ゴール
    cin >> N >> M >> s >> t;

    Graph G(N);
    rep(i,N){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    // 頂点sをスタートとした探索
    seen.assign(N,false);
    dfs(G,s);
    cout << (seen[t]?"Yes":"No") << endl;
}

```
---
# グラフ探索例(2)：二部グラフ判定



---
# グラフ探索例(3)：トポロジカルソート



---
# グラフ探索例(3)：木上の動的計画法



---
# まとめ

- 参考：[DFS (深さ優先探索) 超入門！ 〜 グラフ・アルゴリズムの世界への入口 〜【前編】](https://qiita.com/drken/items/4a7869c5e304883f539b)
- とにかく慣れ:smile:
