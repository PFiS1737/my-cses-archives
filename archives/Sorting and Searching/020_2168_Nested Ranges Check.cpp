// Given n ranges, your task is to determine for each range if it contains some other
// range and if some other range contains it. Range [a,b] contains range [c,d] if a \le c
// and d \le b.
//
// Input
// The first input line has an integer n: the number of ranges.
// After this, there are n lines that describe the ranges. Each line has two integers x
// and y: the range is [x,y]. You may assume that no range appears more than once in the
// input.
//
// Output
// First print a line that describes for each range (in the input order) if it contains
// some other range (1) or not (0). Then print a line that describes for each range (in
// the input order) if some other range contains it (1) or not (0).
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
// 1 0 0 0 
// 0 1 0 1 

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

  int pos = 0;
  for (auto rg : ranges) {
    if (pos >= rg.r) {
      ans[rg.i] = 1;
    }
    pos = max(pos, rg.r);
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
