#include <iostream>
#include <string>
#include <climits>
using namespace std;

char board[50][50];

int go(int n, int m, char first, char second) {
  int ret = 0;
  for(int r=n;r<n+8;++r) {
    for(int c=m;c<m+8;++c) {
      if(r%2==c%2 && board[r][c]==second)
        ret++;
      else if(r%2!=c%2 && board[r][c]==first)
        ret++;
    }
  }
  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  int ans = INT_MAX;
  for(int i=0;i<n;++i) {
    string s; cin >> s;
    for(int j=0;j<s.size();++j)
      board[i][j] = s[j];
  }
  for(int i=0;i<n-7;++i) {
    for(int j=0;j<m-7;++j) {
      ans = min(ans, go(i, j, 'W', 'B'));
      ans = min(ans, go(i, j, 'B', 'W'));
    }
  }
  cout << ans << '\n';
  return 0;
}