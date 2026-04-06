// Consider a two player game where each player has n cards numbered 1,2,\dots,n. On each turn both players place one of their cards on the table. The player who placed the higher card gets one point. If the cards are equal, neither player gets a point. The game continues until all cards have been played.
// You are given the number of cards n and the players' scores at the end of the game, a and b. Your task is to give an example of how the game could have played out.
//
// Input
// The first line contains one integer t: the number of tests.
// Then there are t lines, each with three integers n, a and b.
//
// Output
// For each test case print YES if there is a game with the given outcome and NO otherwise.
// If the answer is YES, print an example of one possible game. Print two lines representing the order in which the players place their cards. You can give any valid example.
//
// Constraints
//
// 1 \le t \le 1000
// 1 \le n \le 100
// 0 \le a,b \le n

// Sample Input
// 5
// 4 1 2
// 2 0 1
// 3 0 0
// 2 1 1
// 4 4 1

// Sample Output
// YES
// 1 2 3 4 
// 1 3 4 2 
// NO
// YES
// 1 2 3 
// 1 2 3 
// YES
// 1 2 
// 2 1 
// NO

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  if (a == 0 && b == 0) {
    goto yes;
  }

  if (a == 0 || b == 0 || a + b > n) {
    cout << "NO" << endl;
    return;
  }

yes:

  cout << "YES" << endl;

  for (int i = 1; i <= n; i++)
    cout << i << " ";
  cout << endl;

  int d = n - a - b;

  for (int i = 1; i <= d; i++) // B + 0
    cout << i << " ";
  for (int i = 1; i <= b; i++) // B + 1
    cout << d + a + i << " ";
  for (int i = 1; i <= a; i++) // A + 1
    cout << d + i << " ";
  cout << endl;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
