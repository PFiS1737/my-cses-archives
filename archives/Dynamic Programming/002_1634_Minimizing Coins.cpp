// Consider a money system consisting of n coins. Each coin has a positive integer value.
// Your task is to produce a sum of money x using the available coins in such a way that
// the number of coins is minimal. For example, if the coins are \{1,5,7\} and the desired
// sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
//
// Input
// The first input line has two integers n and x: the number of coins and the desired sum
// of money. The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each
// coin.
//
// Output
// Print one integer: the minimum number of coins. If it is not possible to produce the
// desired sum, print -1.
//
// Constraints
//
// 1 \le n \le 100
// 1 \le x \le 10^6
// 1 \le c_i \le 10^6

// clang-format off

// Sample Input
// 3 11
// 1 5 7

// Sample Output
// 3

// clang-format on

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using mii = map<int, int>;

#define pb push_back
#define endl "\n"
#define M 1000000007
#define INF 1e9

#define take(x) \
  int x; \
  cin >> x

void solve() {
  take(n);
  take(x);

  vi c(n);
  for (int &i : c)
    cin >> i;

  vi dp(x + 1, INF);

  // 组合出金额为 0 所需的最少硬币数为 0
  dp[0] = 0;

  for (int i = 1; i <= x; i++) {
    // 每次可以选择任意一种硬币，
    // 找到使用不同硬币组合出金额 i 所需的最少硬币数
    for (int j : c) {
      if (i - j >= 0) {
        dp[i] = min(dp[i], dp[i - j] + 1);
      }
    }
  }

  if (dp[x] < INF) {
    cout << dp[x] << endl;
  } else {
    cout << -1 << endl;
  }
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
