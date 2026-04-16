// You are given n cubes in a certain order, and your task is to build towers using them.
// Whenever two cubes are one on top of the other, the upper cube must be smaller than the
// lower cube. You must process the cubes in the given order. You can always either place
// the cube on top of an existing tower, or begin a new tower. What is the minimum
// possible number of towers?
//
// Input
// The first input line contains an integer n: the number of cubes.
// The next line contains n integers k_1,k_2,\ldots,k_n: the sizes of the cubes.
//
// Output
// Print one integer: the minimum number of towers.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le k_i \le 10^9

// clang-format off

// Sample Input
// 5
// 3 8 2 1 5

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

  multiset<int> tops;
  while (n--) {
    int x;
    cin >> x;

    auto it = tops.upper_bound(x); // > x 的元素中最小的
    if (it != tops.end()) {
      tops.erase(it);
    }
    tops.insert(x);
  }

  cout << tops.size() << endl;
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
