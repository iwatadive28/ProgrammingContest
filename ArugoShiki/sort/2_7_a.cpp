#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//
// 生徒情報
struct Student {
    string name;
    long long math;
    long long eng;
};

int main(){
    // INPUT
    ll N;
    cin >> N;

    vector<Student> S(N);
    rep(i,N) cin >> S[i].name >> S[i].math >> S[i].eng;

    // 「数学の点数が高い -> 合計定が低い」の順に並び替える
    // 同じところの順位を保つように、安定ソートを使う
    auto cmp = [&](Student x, Student y) -> bool {
        if (x.math > y.math){
            return true;
        }
        else if (x.math == y.math && x.math + x.eng < y.math + y.eng){
            return true;
        }
        else{
            return false;
        }
    };
    // SORT
    stable_sort(S.begin(), S.end(), cmp);

    // Output
    for (Student s:S){
        cout << s.name << " " << s.math << " " << s.eng << endl;
    }
    return 0;
}