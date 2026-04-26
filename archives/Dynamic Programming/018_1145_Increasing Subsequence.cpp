// You are given an array containing n integers. Your task is to determine the longest
// increasing subsequence in the array, i.e., the longest subsequence where every element
// is larger than the previous one. A subsequence is a sequence that can be derived from
// the array by deleting some elements without changing the order of the remaining
// elements.
//
// Input
// The first line contains an integer n: the size of the array.
// After this there are n integers x_1,x_2,\ldots,x_n: the contents of the array.
//
// Output
// Print the length of the longest increasing subsequence.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// clang-format off

// Sample Input
// 8
// 7 3 5 3 6 2 9 8

// Sample Output
// 4

// clang-format on

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using mii = map<int, int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvll = vector<vll>;

#define pb push_back
#define endl "\n"
#define M 1000000007
#define INF 1e9

#define takei(x) \
  int x; \
  cin >> x

#define takevi(v, n) \
  vi v(n + 1); \
  for (int i = 1; i <= n; i++) \
  cin >> v[i]

void solve() {
  takei(n);

  // dp[i] 表示：长度为 i+1 的递增子序列中，“结尾最小”的那个结尾值
  vi dp;

  for (int i = 0; i < n; i++) {
    takei(x);

    auto it = lower_bound(dp.begin(), dp.end(), x);
    if (it == dp.end()) {
      dp.pb(x);
    } else {
      *it = x;
    }
  }

  cout << dp.size() << endl;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
