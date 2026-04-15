// You are given an array of n integers, and your task is to find two values (at distinct
// positions) whose sum is x.
//
// Input
// The first input line has two integers n and x: the array size and the target sum.
// The second line has n integers a_1,a_2,\dots,a_n: the array values.
//
// Output
// Print two integers: the positions of the values. If there are several solutions, you
// may print any of them. If there are no solutions, print IMPOSSIBLE.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x,a_i \le 10^9

// clang-format off

// Sample Input
// 4 8
// 2 7 5 1

// Sample Output
// 2 4

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
  int n, x;
  cin >> n >> x;

  map<int, int> mp;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;

    int b = x - a;
    if (mp.count(b)) {
      cout << mp[b] << " " << i << endl;
      return;
    }

    mp[a] = i;
  }

  cout << "IMPOSSIBLE" << endl;
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
