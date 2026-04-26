// Given an array of n integers, your task is to calculate the number of increasing
// subsequences it contains. If two subsequences have the same values but in different
// positions in the array, they are counted separately.
//
// Input
// The first input line has an integer n: the size of the array.
// The second line has n integers x_1,x_2,\dots,x_n: the contents of the array.
//
// Output
// Print one integer: the number of increasing subsequences modulo 10^9+7.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// clang-format off

// Sample Input
// 3
// 2 1 3

// Sample Output
// 5

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

struct BIT {
  int n;
  vi t;

  BIT(int n) : n(n), t(n + 1, 0) {
  }

  static inline int lowbit(int x) {
    return x & -x;
  }

  void update(int i, int v) {
    for (; i <= n; i += lowbit(i)) {
      t[i] = (t[i] + v) % M;
    }
  }

  int query(int i) {
    int res = 0;
    for (; i > 0; i -= lowbit(i)) {
      res = (res + t[i]) % M;
    }
    return res;
  }
};

void solve() {
  take(int, n);

  vi a(n);
  for (int &i : a)
    cin >> i;

  // 坐标压缩
  vi b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());

  auto get = [&](int x) {
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
  };

  BIT bit(b.size());

  for (int i = 0; i < n; i++) {
    int x = get(a[i]);
    bit.update(x, bit.query(x - 1) + 1);
  }

  cout << bit.query(b.size()) << endl;
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
