// Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. During
// the game, every other child is removed from the circle until there are no children
// left. In which order will the children be removed?
//
// Input
// The only input line has an integer n.
//
// Output
// Print n integers: the removal order.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5

// clang-format off

// Sample Input
// 7

// Sample Output
// 2 4 6 1 5 3 7 

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

  vi arr(n);
  iota(arr.begin(), arr.end(), 1);

  for (unsigned i = 0; i < arr.size(); i++) {
    if (i % 2) {
      cout << arr[i] << " ";
    } else {
      arr.pb(arr[i]);
    }
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
