#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<yl/debug.h>
#else
#define debug(...) 0
#endif

const int64_t MOD = 998244353;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x: a) cin >> x;
  int64_t ans = n; // choose 1, always 

  for (int term = 2; term <= n; term++) {
    vector<vector<int64_t>> pp(n+1, vector<int64_t>(term));
    vector<vector<int64_t>> dp(n+1, vector<int64_t>(term));
    pp[0][0] = 1;
    for (int k = 0; k < n; k++) {
      int x = a[k] % term;
      dp = pp;
      for (int y = 0; y <= k; y++) {
        for (int i = 0; i < term; i++) {
          dp[y + 1][(i + x) % term] = (dp[y + 1][(i + x) % term] + pp[y][i]) % MOD;
        }
      }
      swap(dp, pp);
      // debug(pp);
    }
    // debug(term, pp);
    // debug(term, pp[term][0]);
    ans = (ans + pp[term][0]) % MOD;
  }
  cout << ans << endl;
}
