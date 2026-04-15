// You have n coins with positive integer values. What is the smallest sum you cannot
// create using a subset of the coins?
//
// Input
// The first line has an integer n: the number of coins.
// The second line has n integers x_1,x_2,\dots,x_n: the value of each coin.
//
// Output
// Print one integer: the smallest coin sum.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// clang-format off

// Sample Input
// 5
// 2 9 1 2 7

// Sample Output
// 6

// clang-format on

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define pb push_back
#define endl "\n"

void solve() {
  int n;
  cin >> n;

  vi arr(n);
  for (int &i : arr)
    cin >> i;

  sort(arr.begin(), arr.end());

  // NOTE: 假设可以用一部分硬币组成所有和 1, 2, ..., k ；
  // 那么，如果我们添加一枚新硬币，其价值 x 至多为 k+1 ，
  // 我们可以组成所有和 1, 2, ..., k+x（这是显然的）。
  // 但如果该硬币的值大于 k+1 ，则添加该硬币后，我们无法组成和 k+1 。

  ll ans = 1;
  for (int i : arr) {
    if (i > ans)
      break;
    ans += i;
  }

  cout << ans << endl;
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
