// A factory has n machines which can be used to make products. Your goal is to make a
// total of t products. For each machine, you know the number of seconds it needs to make
// a single product. The machines can work simultaneously, and you can freely decide their
// schedule. What is the shortest time needed to make t products?
//
// Input
// The first input line has two integers n and t: the number of machines and products.
// The next line has n integers k_1,k_2,\dots,k_n: the time needed to make a product using
// each machine.
//
// Output
// Print one integer: the minimum time needed to make t products.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le t \le 10^9
// 1 \le k_i \le 10^9

// clang-format off

// Sample Input
// 3 7
// 3 2 5

// Sample Output
// 8

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
  int n, t;
  cin >> n >> t;

  vi times(n);
  for (int &i : times) {
    cin >> i;
  }

  auto check = [&](ll x) {
    ll total = 0;
    for (int i : times) {
      total += x / i;
      if (total >= t)
        return true;
    }
    return false;
  };

  ll k = 0;
  for (ll b = 1e18; b >= 1; b /= 2) {
    while (!check(k + b))
      k += b;
  }

  cout << k + 1 << endl;
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
