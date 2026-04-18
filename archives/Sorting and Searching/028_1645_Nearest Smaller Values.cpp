// Given an array of n integers, your task is to find for each array position the nearest
// position to its left having a smaller value.
//
// Input
// The first input line has an integer n: the size of the array.
// The second line has n integers x_1,x_2,\dots,x_n: the array values.
//
// Output
// Print n integers: for each array position the nearest position with a smaller value. If
// there is no such position, print 0.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// clang-format off

// Sample Input
// 8
// 2 5 1 4 8 3 2 5

// Sample Output
// 0 1 0 3 4 3 3 7 

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

  stack<pii> s;

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    while (!s.empty() && s.top().first >= x) {
      s.pop();
    }

    if (!s.empty()) {
      cout << s.top().second << " ";
    } else {
      cout << "0 ";
    }

    s.push({x, i});
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
