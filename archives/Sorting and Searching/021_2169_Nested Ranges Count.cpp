// Given n ranges, your task is to count for each range how many other ranges it contains
// and how many other ranges contain it. Range [a,b] contains range [c,d] if a \le c and d
// \le b.
//
// Input
// The first input line has an integer n: the number of ranges.
// After this, there are n lines that describe the ranges. Each line has two integers x
// and y: the range is [x,y]. You may assume that no range appears more than once in the
// input.
//
// Output
// First print a line that describes for each range (in the input order) how many other
// ranges it contains. Then print a line that describes for each range (in the input
// order) how many other ranges contain it.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x < y \le 10^9

// clang-format off

// Sample Input
// 4
// 1 6
// 2 4
// 4 8
// 3 6

// Sample Output
// 2 0 0 0 
// 0 1 0 1 

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

struct Range {
  int l, r, i;

  // NOTE: l 相同的区间，按 r 从大到小排序
  bool operator<(Range o) const {
    if (l != o.l) {
      return l < o.l;
    }
    return r > o.r;
  }
};

void check(vector<Range> ranges) {
  vi ans(ranges.size());
  indexed_set<pii> pos;

  for (auto rg : ranges) {
    ans[rg.i] = pos.size() - pos.order_of_key({rg.r, 0});
    pos.insert({rg.r, rg.i});
  }

  for (int i : ans) {
    cout << i << " ";
  }
  cout << endl;
}

void solve() {
  int n;
  cin >> n;

  vector<Range> r1;
  vector<Range> r2;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    r1.pb({y, x, i});
    r2.pb({x, y, i});
  }

  sort(r1.begin(), r1.end());
  sort(r2.begin(), r2.end());

  check(r1);
  check(r2);
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
