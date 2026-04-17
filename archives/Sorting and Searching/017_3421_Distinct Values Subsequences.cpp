// Given an array of n integers, count the number of subsequences where each element is
// distinct. A subsequence is a sequence of array elements from left to right that may
// have gaps.
//
// Input
// The first line has an integer n: the array size.
// The second line has n integers x_1,x_2,\dots,x_n: the array contents.
//
// Output
// Print the number of subsequences with distinct elements. The answer can be large, so
// print it modulo 10^9+7.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// clang-format off

// Sample Input
// 4
// 1 2 1 3

// Sample Output
// 11

// clang-format on

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
using mii = map<int, int>;

#define pb push_back
#define endl "\n"
#define M 1000000007

void solve() {
  int n;
  cin >> n;

  mii mp;
  while (n--) {
    int x;
    cin >> x;
    mp[x]++;
  }

  ll ans = 1;
  for (auto &[_, v] : mp) {
    ans *= v + 1;
    ans %= M;
  }

  cout << ans - 1 << endl;
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
