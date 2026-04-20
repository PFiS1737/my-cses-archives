// In a movie festival, n movies will be shown. Syrjälä's movie club consists of k
// members, who will be all attending the festival. You know the starting and ending time
// of each movie. What is the maximum total number of movies the club members can watch
// entirely if they act optimally?
//
// Input
// The first input line has two integers n and k: the number of movies and club members.
// After this, there are n lines that describe the movies. Each line has two integers a
// and b: the starting and ending time of a movie.
//
// Output
// Print one integer: the maximum total number of movies.
//
// Constraints
//
// 1 \le k \le n \le 2 \cdot 10^5
// 1 \le a < b \le 10^9

// clang-format off

// Sample Input
// 5 2
// 1 5
// 8 10
// 3 6
// 2 5
// 6 9

// Sample Output
// 4

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
  int n, k;
  cin >> n >> k;

  vector<pii> evts;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    evts.pb({b, a});
  }

  sort(evts.begin(), evts.end());

  // 记录每个成员的结束时间，即他可以看下一个电影的时间，初始为0
  multiset<int> t;
  for (int i = 1; i <= k; i++) {
    t.insert(0);
  }

  // INFO: 其余逻辑参考 006_1629

  int cnt = 0;
  for (auto [b, a] : evts) {
    auto it = t.upper_bound(a);
    if (it == t.begin())
      continue;
    cnt++;
    it--;
    t.erase(it);
    t.insert(b);
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
