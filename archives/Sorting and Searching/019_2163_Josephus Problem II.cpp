// Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. During
// the game, repeatedly k children are skipped and one child is removed from the circle.
// In which order will the children be removed?
//
// Input
// The only input line has two integers n and k.
//
// Output
// Print n integers: the removal order.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 0 \le k \le 10^9

// clang-format off

// Sample Input
// 7 2

// Sample Output
// 3 6 2 7 5 1 4 

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
using mii = map<int, int>;

#define pb push_back
#define endl "\n"
#define M 1000000007

void solve() {
  int n, k;
  cin >> n >> k;

  indexed_set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }

  int pos = 0;
  for (int i = 1; i <= n; i++) {
    pos = (pos + k) % (n - i + 1);
    // auto it = next(s.begin(), pos); // TIME LIMIT EXCEEDED
    auto it = s.find_by_order(pos);
    cout << *it << " ";
    s.erase(it);
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
