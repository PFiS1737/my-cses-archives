// Given a string, your task is to generate all different strings that can be created
// using its characters.
//
// Input
// The only input line has a string of length n. Each character is between a–z.
//
// Output
// First print an integer k: the number of strings. Then print k lines: the strings in
// alphabetical order.
//
// Constraints
//
// 1 \le n \le 8

// clang-format off

// Sample Input
// aabac

// Sample Output
// 20
// aaabc
// aaacb
// aabac
// aabca
// aacab
// aacba
// abaac
// abaca
// abcaa
// acaab
// acaba
// acbaa
// baaac
// baaca
// bacaa
// bcaaa
// caaab
// caaba
// cabaa
// cbaaa

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

void solve() {
  string s;
  cin >> s;

  sort(s.begin(), s.end());

  vector<string> ans;
  do {
    ans.pb(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << ans.size() << endl;
  for (auto &s : ans) {
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
