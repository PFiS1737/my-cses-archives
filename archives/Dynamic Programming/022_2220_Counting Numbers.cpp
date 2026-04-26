// Your task is to count the number of integers between a and b where no two adjacent
// digits are the same.
//
// Input
// The only input line has two integers a and b.
//
// Output
// Print one integer: the answer to the problem.
//
// Constraints
//
// 0 \le a \le b \le 10^{18}

// clang-format off

// Sample Input
// 123 321

// Sample Output
// 171

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

#define take(ty, ...) \
  ty __VA_ARGS__; \
  see(__VA_ARGS__)

#define takevi(v, n) \
  vi v(n + 1); \
  for (int i = 1; i <= n; i++) \
  cin >> v[i]

// TODO:

string s;
map<array<int, 4>, ll> lookup;

ll recurse(int i, int prev, bool equal, bool empty) {
  if (i == (int)s.size())
    return 1;

  array<int, 4> params{i, prev, equal, empty};
  if (lookup.count(params))
    return lookup[params];

  ll result = 0;
  for (int d = 0; d < 10; d++) {
    if (equal && d > s[i] - '0')
      break;
    if (!empty && d == prev)
      continue;
    result += recurse(i + 1, d, equal && d == s[i] - '0', empty && d == 0);
  }

  lookup[params] = result;
  return result;
}

ll count(ll x) {
  if (x < 0)
    return 0;
  s = to_string(x);
  lookup.clear();
  return recurse(0, 0, true, true);
}

void solve() {
  take(ll, a, b);
  cout << count(b) - count(a - 1) << endl;
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
