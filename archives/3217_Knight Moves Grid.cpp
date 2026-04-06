// There is a knight on an n \times n chessboard. For each square, print the minimum number of moves the knight needs to do to reach the top-left corner.
//
// Input
// The only line has an integer n.
//
// Output
// Print the number of moves for each square.
//
// Constraints
//
// 4 \le n \le 1000

// Sample Input
// 8

// Sample Output
// 0 3 2 3 2 3 4 5
// 3 4 1 2 3 4 3 4
// 2 1 4 3 2 3 4 5
// 3 2 3 2 3 4 3 4
// 2 3 2 3 4 3 4 5
// 3 4 3 4 3 4 5 4
// 4 3 4 3 4 5 4 5
// 5 4 5 4 5 4 5 6

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define pb push_back
#define endl "\n"

int dx[] = {1, 1, -1, -1, -2, 2, -2, 2};
int dy[] = {-2, 2, -2, 2, 1, 1, -1, -1};

void solve() {
  int n;
  cin >> n;

  queue<pii> q;
  vector<vector<int>> dist(n, vector(n, -1));

  q.push({0, 0});
  dist[0][0] = 0;

  while (q.size()) {
    auto [x, y] = q.front();
    q.pop();

    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n || dist[nx][ny] != -1) {
        continue;
      }
      dist[nx][ny] = dist[x][y] + 1;
      q.push({nx, ny});
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dist[i][j] << " \n"[j == n - 1];
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
