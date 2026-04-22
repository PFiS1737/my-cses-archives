// Consider a money system consisting of n coins. Each coin has a positive integer value.
// Your task is to calculate the number of distinct ways you can produce a money sum x
// using the available coins. For example, if the coins are \{2,3,5\} and the desired sum
// is 9, there are 8 ways:
//
// 2+2+5
// 2+5+2
// 5+2+2
// 3+3+3
// 2+2+2+3
// 2+2+3+2
// 2+3+2+2
// 3+2+2+2
//
// Input
// The first input line has two integers n and x: the number of coins and the desired sum
// of money. The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each
// coin.
//
// Output
// Print one integer: the number of ways modulo 10^9+7.
//
// Constraints
//
// 1 \le n \le 100
// 1 \le x \le 10^6
// 1 \le c_i \le 10^6

// clang-format off

// Sample Input
// 3 9
// 2 3 5

// Sample Output
// 8

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

  vll dp(x + 1);

  dp[0] = 1;

  for (int i = 1; i <= x; i++) {
    for (int j : c) {
      if (i - j >= 0) {
        dp[i] = (dp[i] + dp[i - j]) % M;
      }
    }
  }

  cout << dp[x] << endl;
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
