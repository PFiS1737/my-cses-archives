// There are n apples with known weights. Your task is to divide the apples into two
// groups so that the difference between the weights of the groups is minimal.
//
// Input
// The first input line has an integer n: the number of apples.
// The next line has n integers p_1,p_2,\dots,p_n: the weight of each apple.
//
// Output
// Print one integer: the minimum difference between the weights of the groups.
//
// Constraints
//
// 1 \le n \le 20
// 1 \le p_i \le 10^9

// clang-format off

// Sample Input
// 5
// 3 2 7 4 1

// Sample Output
// 1

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

void solve() {
  int n;
  cin >> n;
  vi arr(n);
  ll m = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    m += arr[i];
  }
  for (ull i = 0; i < (1ull << n); i++) {
    ll s = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1ull << j)) {
        s += arr[j];
      } else {
        s -= arr[j];
      }
    }
    m = min(m, abs(s));
  }
  cout << m << endl;
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
