// There are n applicants and m free apartments. Your task is to distribute the apartments
// so that as many applicants as possible will get an apartment. Each applicant has a
// desired apartment size, and they will accept any apartment whose size is close enough
// to the desired size.
//
// Input
// The first input line has three integers n, m, and k: the number of applicants, the
// number of apartments, and the maximum allowed difference. The next line contains n
// integers a_1, a_2, \ldots, a_n: the desired apartment size of each applicant. If the
// desired size of an applicant is x, they will accept any apartment whose size is between
// x-k and x+k. The last line contains m integers b_1, b_2, \ldots, b_m: the size of each
// apartment.
//
// Output
// Print one integer: the number of applicants who will get an apartment.
//
// Constraints
//
// 1 \le n, m \le 2 \cdot 10^5
// 0 \le k \le 10^9
// 1 \le a_i, b_i \le 10^9

// clang-format off

// Sample Input
// 5
// 2 3 2 2 3

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
  int n, m, k;
  cin >> n >> m >> k;

  vi a(n), b(m);
  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int i = 0, j = 0, cnt = 0;
  while (i < n && j < m) {
    if (abs(a[i] - b[j]) <= k) {
      cnt++;
      i++;
      j++;
    } else if (a[i] - b[j] > k) {
      j++;
    } else { // b[i] - a[j] > k
      i++;
    }
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
