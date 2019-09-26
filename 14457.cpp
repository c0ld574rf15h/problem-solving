#include <iostream>
#include <string>
using namespace std;

int N, ans = 0;
int a[10][10];

void toggle(int r, int c) {
  ans += 1;
  for(int i=0;i<=r;++i)
    for(int j=0;j<=c;++j)
      a[i][j] = 1- a[i][j];
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for(int i=0;i<N;++i) {
    string s; cin >> s;
    for(int j=0;j<N;++j)
      a[i][j] = s[j]-'0';
  }
  for(int i=N-1;i>=0;--i)
    for(int j=N-1;j>=0;--j)
      if(a[i][j]==1) toggle(i, j);
  cout << ans << '\n';
  return 0;
}