// Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
//
// Input
// The only input line has a string of length n consisting of characters A–Z.
//
// Output
// Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
//
// Constraints
//
// 1 \le n \le 10^6

// Sample Input
// AAAACACBA

// Sample Output
// AACABACAA

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

  int cc[26] = {0};
  for (char c : s) {
    cc[c - 'A']++;
  }

  char odd = 0;
  for (int i = 0; i < 26; i++) {
    if (cc[i] % 2 == 1) {
      if (odd) {
        cout << "NO SOLUTION\n";
        return;
      }
      odd = 'A' + i;
      cc[i]--;
    }
    cc[i] /= 2;
  }

  string ans;
  for (int i = 0; i < 26; i++) {
    ans += string(cc[i], 'A' + i);
  }
  cout << ans;

  if (odd) {
    cout << odd;
  }

  reverse(ans.begin(), ans.end());
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
