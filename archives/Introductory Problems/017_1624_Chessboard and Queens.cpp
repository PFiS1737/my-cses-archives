// Your task is to place eight queens on a chessboard so that no two queens are attacking
// each other. As an additional challenge, each square is either free or reserved, and you
// can only place queens on the free squares. However, the reserved squares do not prevent
// queens from attacking each other. How many possible ways are there to place the queens?
//
// Input
// The input has eight lines, and each of them has eight characters. Each square is either
// free (.) or reserved (*).
//
// Output
// Print one integer: the number of ways you can place the queens.

// clang-format off

// Sample Input
// ........
// ........
// ..*.....
// ........
// ........
// .....**.
// ...*....
// ........

// Sample Output
// 65

// clang-format on

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

#define N 8

string ss[N];
bool col[N], d1[N * 2], d2[N * 2];
int cnt = 0;

void search(int y) {
  if (y == N) {
    cnt++;
    return;
  }
  for (int x = 0; x < N; x++) {
    if (ss[y][x] == '*' || col[x] || d1[y + x] || d2[y - x + N]) {
      continue;
    }

    col[x] = d1[y + x] = d2[y - x + N] = true;

    search(y + 1);

    col[x] = d1[y + x] = d2[y - x + N] = false;
  }
}

void solve() {
  for (int i = 0; i < 8; i++) {
    cin >> ss[i];
  }
  search(0);
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
