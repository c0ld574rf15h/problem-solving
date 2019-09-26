#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int a[100001][4];

bool win(int a, int b) {
  return (a==1&&b==2) || (a==2&&b==3) || (a==3&&b==1);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for(int i=1;i<=N;++i) {
    char c; cin >> c;
    if(c=='H') a[i][0] = 1;
    else if(c=='S') a[i][0] = 2;
    else a[i][0] = 3;
  }
  for(int i=1;i<=N;++i) {
    for(int j=1;j<=3;++j) {
      if(win(j, a[i][0])) a[i][j] = a[i-1][j] + 1;
      else a[i][j] = a[i-1][j];
    }
  }
  for(int i=1;i<=N-1;++i)
    for(int j=1;j<=3;++j)
      for(int k=1;k<=3;++k)
        ans = max(ans, a[i][j] + a[N][k] - a[i][k]);
  cout << ans << '\n';
  return 0;
}