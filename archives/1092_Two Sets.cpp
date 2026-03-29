// Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
//
// Input
// The only input line contains an integer n.
//
// Output
// Print "YES", if the division is possible, and "NO" otherwise.
// After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
//
// Constraints
//
// 1 \le n \le 10^6

// Sample Input
// 7

// Sample Output
// YES
// 3
// 7 6 1 
// 4
// 5 4 3 2 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back

void solve() {
  ll n;
  cin >> n;

  ll sum = n * (n + 1) / 2;

  if (sum % 2 == 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";

    vi s1, s2;
    sum /= 2;

    for (int i = n; i >= 1; i--) {
      if (i <= sum) {
        s1.pb(i);
        sum -= i;
      } else {
        s2.pb(i);
      }
    }

    cout << s1.size() << "\n";
    for (int n : s1) {
      cout << n << " ";
    }
    cout << "\n" << s2.size() << "\n";
    for (int n : s2) {
      cout << n << " ";
    }
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
