// There are 88418 paths in a 7 \times 7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).
// For example, the path
//
// corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.
// You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.
//
// Input
// The only input line has a 48-character string of characters ?, D, U, L and R.
//
// Output
// Print one integer: the total number of paths.

// Sample Input
// ??????R??????U??????????????????????????LD????D?

// Sample Output
// 201

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define pb push_back
#define endl "\n"

#define N 7

int G[N + 2][N + 2];
string path;
int cnt = 0;

void search(int y, int x, int i) {
  // 如果已经走过了，或者出界了，直接返回
  if (G[y][x])
    return;

  // 如果走到终点（左下角），就返回
  if (y == N && x == 1) {
    // 如果走满了，计数器+1
    if (i == N * N - 1)
      cnt++;
    return;
  }

  bool down = G[y + 1][x];
  bool up = G[y - 1][x];
  bool left = G[y][x - 1];
  bool right = G[y][x + 1];

  // NOTE: 关键剪枝：
  //       可以证明，如果一个格子上下都被走过了，但左右没走过
  //      （你只可能是你从上或下某一个方向走到的这个格子）
  //       那么无论接下来怎么走，都不可能走满。
  //       另一种方向同理。
  if (down && up && !left && !right)
    return;
  if (!down && !up && left && right)
    return;

  char c = path[i];

  G[y][x] = 1;

  if (c == '?' || c == 'D')
    search(y + 1, x, i + 1);
  if (c == '?' || c == 'U')
    search(y - 1, x, i + 1);
  if (c == '?' || c == 'L')
    search(y, x - 1, i + 1);
  if (c == '?' || c == 'R')
    search(y, x + 1, i + 1);

  G[y][x] = 0;
}

void solve() {
  // HACK: 最外面一圈设为 1，方便越界检查
  for (int i = 0; i <= N + 1; i++) {
    G[0][i] = G[N + 1][i] = 1;
    G[i][0] = G[i][N + 1] = 1;
  }

  cin >> path;
  search(1, 1, 0);
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
