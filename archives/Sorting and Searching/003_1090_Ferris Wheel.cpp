// There are n children who want to go to a Ferris wheel, and your task is to find a
// gondola for each child. Each gondola may have one or two children in it, and in
// addition, the total weight in a gondola may not exceed x. You know the weight of every
// child. What is the minimum number of gondolas needed for the children?
//
// Input
// The first input line contains two integers n and x: the number of children and the
// maximum allowed weight. The next line contains n integers p_1,p_2,\ldots,p_n: the
// weight of each child.
//
// Output
// Print one integer: the minimum number of gondolas.
//
// Constraints
//
// 1 \le n \le 2 \cdot 10^5
// 1 \le x \le 10^9
// 1 \le p_i \le x

// clang-format off

// Sample Input
// 4 10
// 7 2 3 9

// Sample Output
// 3

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
  int n, x;
  cin >> n >> x;

  vi arr(n);
  for (int &i : arr)
    cin >> i;

  sort(arr.begin(), arr.end());

  int l = 0, cnt = 0;
  for (int r = n - 1; r >= l; r--) {
    if (arr[r] + arr[l] <= x) {
      l++;
    }
    cnt++;
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
