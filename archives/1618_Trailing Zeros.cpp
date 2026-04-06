// Your task is to calculate the number of trailing zeros in the factorial n!.
// For example, 20!=2432902008176640000 and it has 4 trailing zeros.
//
// Input
// The only input line has an integer n.
//
// Output
// Print the number of trailing zeros in n!.
//
// Constraints
//
// 1 \le n \le 10^9

// clang-format off

// Sample Input
// 395

// Sample Output
// 97

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
  // https://stackoverflow.com/q/23977727
  int ans = 0;
  while (n > 0) {
    n /= 5;
    ans += n;
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
