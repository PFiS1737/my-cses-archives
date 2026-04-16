// You are given an array that contains each number between 1 \dots n exactly once. Your
// task is to collect the numbers from 1 to n in increasing order. On each round, you go
// through the array from left to right and collect as many numbers as possible. Given m
// operations that swap two numbers in the array, your task is to report the number of
// rounds after each operation.
//
// Input
// The first line has two integers n and m: the array size and the number of operations.
// The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
// Finally, there are m lines that describe the operations. Each line has two integers a
// and b: the numbers at positions a and b are swapped.
//
// Output
// Print m integers: the number of rounds after each swap.
//
// Constraints
//
// 1 \le n, m \le 2 \cdot 10^5
// 1 \le a,b \le n

// clang-format off

// Sample Input
// 5 3
// 4 2 1 5 3
// 2 3
// 1 5
// 2 3

// Sample Output
// 2
// 3
// 4

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
  int n, m;
  cin >> n >> m;

  vi val(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
    pos[val[i]] = i;
  }

  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (pos[i - 1] > pos[i])
      cnt++;
  }

  auto check = [&](int x) -> int {
    return x > 1 && x <= n && pos[x - 1] > pos[x];
  };

  while (m--) {
    int a, b;
    cin >> a >> b;

    int x = val[a], y = val[b];

    set<int> s = {x, x + 1, y, y + 1};

    for (int v : s)
      cnt -= check(v);

    swap(val[a], val[b]);
    swap(pos[x], pos[y]);

    for (int v : s)
      cnt += check(v);

    cout << cnt << endl;
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
