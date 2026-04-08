// A Gray code is a list of all 2^n bit strings of length n, where any two successive
// strings differ in exactly one bit (i.e., their Hamming distance is one). Your task is
// to create a Gray code for a given length n.
//
// Input
// The only input line has an integer n.
//
// Output
// Print 2^n lines that describe the Gray code. You can print any valid solution.
//
// Constraints
//
// 1 \le n \le 16

// clang-format off

// Sample Input
// 2

// Sample Output
// 00
// 01
// 11
// 10

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

vector<string> genGray(int n) {
  if (n == 1) {
    return {"0", "1"};
  }
  auto arr = genGray(n - 1);
  vector<string> ans;
  for (string s : arr) {
    ans.pb("0" + s);
  }
  for (auto it = arr.rbegin(); it != arr.rend(); it++) {
    ans.pb("1" + *it);
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  auto ans = genGray(n);
  for (string s : ans) {
    cout << s << endl;
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
