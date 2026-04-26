// There are n projects you can attend. For each project, you know its starting and ending
// days and the amount of money you would get as reward. You can only attend one project
// during a day. What is the maximum amount of money you can earn?
//
// Input
// The first input line contains an integer n: the number of projects.
// After this, there are n lines. Each such line has three integers a_i, b_i, and p_i: the
// starting day, the ending day, and the reward.
//
// Output
// Print one integer: the maximum amount of money you can earn.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le a_i \le b_i \le 10^9
// 1 \le p_i \le 10^9

// clang-format off

// Sample Input
// 4
// 2 4 4
// 3 6 6
// 6 8 2
// 5 7 3

// Sample Output
// 7

// clang-format on

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using mii = map<int, int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvll = vector<vll>;

#define pb push_back
#define endl "\n"
#define M 1000000007
#define INF 1e9

template <typename... T> inline void see(T &...args) {
  ((cin >> args), ...);
}

#define takei(...) \
  int __VA_ARGS__; \
  see(__VA_ARGS__)

#define takevi(v, n) \
  vi v(n + 1); \
  for (int i = 1; i <= n; i++) \
  cin >> v[i]

struct Event {
  int t, i, p;
  enum Type { START, END } type;
  bool operator<(const Event &o) const {
    if (t == o.t) {
      return type < o.type; // START comes before END if times are equal
    }
    return t < o.t;
  }
};

void solve() {
  takei(n);

  vector<Event> events;
  for (int i = 0; i < n; i++) {
    takei(a, b, p);
    events.push_back({a, i, p, Event::START});
    events.push_back({b, i, p, Event::END});
  }
  sort(events.begin(), events.end());

  vll dp(n);

  ll ans = 0;
  for (auto [t, i, p, ty] : events) {
    if (ty == Event::START) {
      dp[i] = ans + p;
    } else {
      ans = max(ans, dp[i]);
    }
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
