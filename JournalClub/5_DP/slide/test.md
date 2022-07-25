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
![bg brightness:0.6](img/cat_pc.jpg.webp)
# アルゴリズムとデータ構造<br>動的計画法 <!-- omit in toc -->

---
![bg right:40% 80% ](img/book.jpg)

# 目次 <!-- omit in toc -->
- [動的計画法とは？](#動的計画法とは)
- [ABC261_D_Flipping and Bonus](#abc261_d_flipping-and-bonus)
- [Flog問題](#flog問題)
- [配るDPと貰うDP](#配るdpと貰うdp)
- [ナップサック問題](#ナップサック問題)
- [編集距離を求める問題](#編集距離を求める問題)
- [まとめ](#まとめ)

---
# 動的計画法とは？

動的計画法（dynamic prigramming,DP）はアルゴリズム設計技法の一つです。

一言で言えば、**「与えられた問題全体を一連の部分問題に上手に分解し、各部分問題に対する解をメモ化しながら、小さな部分問題からより大きな部分問題へと順に解を求めていく手法」** です。

---

動的計画法は非常に汎用性の強い手法であり、コンピュータサイエンス上の重要な問題から、世の中のさまざまな現場における最適化問題まで、広範囲の問題を解くのに役立ちます！

- ナップサック問題
- スケジューリング問題
- 発電計画問題
- 編集距離を求める問題 (diff コマンドの仕組みです)
- 音声認識パターンマッチング問題
- 文章の分かち書きをする問題
- 隠れマルコフ問題
  
---

解決できる問題の幅が広い＝手法を適用するバリエーションが多彩で習得が難しい

ただ、設計パターン自体はそれほど多くないので、「習うより慣れろ！」精神で経験すれば習得できる。

・・・らしいです。

---
# [ABC261_D_Flipping and Bonus](https://atcoder.jp/contests/abc261/tasks/abc261_d)

高橋君が N 回コイントスを行います。 また、高橋君はカウンタを持っており、最初カウンタの数値は 0 です。 i 回目のコイントスで表裏のどちらが出たかによって、次のことが起こります。
- 表が出たとき：高橋君はカウンタの数値を 1 増やし、X_i円もらう。
- 裏が出たとき：高橋君はカウンタの数値を 0 に戻す。お金をもらうことは出来ない。

また、M 種類の連続ボーナスがあり、i 種類目の連続ボーナスではカウンタの数値が CiになるたびにYi円もらうことができます。
高橋君は最大で何円もらうことができるかを求めてください。

参考：[iwasa提出コード](https://github.com/iwatadive28/ProgrammingContest/blob/main/ABC/ABC261/D.cpp)

---
貰えるお金は試行回数とカウンタの数値で決まる。

「試行回数 i 回」*「カウンタ j」ような条件の下で 1 回目から i 回目までで得られる金額の最大値を更新していく。

---
メモ(2次元配列dp)を作成。
0回目、カウント0からスタートするため、[0][0]のみ初期値を入れ、ほかは外れ値を入れておく。

```c++
// 初期化
vector<vector<ll>> dp(N+1,vector<ll>(N+1,-1));
dp[0][0] = 0;
```
![bg right:50% 90%](img/ABC261_D_init.png)


---
あるi,jに着目すると、裏になるパターンと表になるパターンの2通りの動作があることが分かる。
```c++
// 配るDP
rep(i,N){
    rep(j,N){
        if(dp[i][j]==-1) continue;
        // 表の場合
        dp[i+1][j+1] = dp[i][j]+X[i]+CY[j+1];
        // 裏の場合
        dp[i+1][0] = max(dp[i+1][0],dp[i][j]);
    }
}
```
![bg right:40% 100%](img/ABC261_D_simple.png)

---

入力例1
> 6 3
2 7 1 8 2 8
2 10
3 1
5 5

出力例1
> 48

![bg right:70% 90%](img/ABC261_D_sample1.png)

---
# Flog問題

---
# 配るDPと貰うDP

---
# ナップサック問題


---
# 編集距離を求める問題

---

---
# まとめ

複雑な問題をシンプルな部分問題に上手に分解することがポイントです。
設計手法に慣れましょう。

- [アルゴ式](https://algo-method.com/courses/7)：この本の著者の管理する学習コンテンツ
- [EPDC](https://atcoder.jp/contests/dp)：解き進めましょう