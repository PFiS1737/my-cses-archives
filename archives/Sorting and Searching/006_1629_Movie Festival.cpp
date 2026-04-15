// In a movie festival n movies will be shown. You know the starting and ending time of
// each movie. What is the maximum number of movies you can watch entirely?
//
// Input
// The first input line has an integer n: the number of movies.
// After this, there are n lines that describe the movies. Each line has two integers a
// and b: the starting and ending times of a movie.
//
// Output
// Print one integer: the maximum number of movies.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le a < b \le 10^9

// clang-format off

// Sample Input
// 3
// 3 5
// 4 9
// 5 8

// Sample Output
// 2

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

  vector<pii> v(n);
  for (auto &[start, end] : v) {
    cin >> start >> end;
  }

  // NOTE: 按结束时间排序，贪心地选择结束最早的活动
  sort(v.begin(), v.end(), [](auto a, auto b) {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second < b.second;
  });

  int last = -1, cnt = 0;
  for (auto &[start, end] : v) {
    if (start >= last) {
      last = end;
      cnt++;
    }
  }

  cout << cnt << endl;
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
