#include <iostream>
using namespace std;

int a[501][2];
int dp[501][501];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for(int i=1;i<=n;++i) cin >> a[i][0] >> a[i][1];
  for(int i=1;i<=n-1;++i) dp[i][i+1] = a[i][0]*a[i][1]*a[i+1][1];
  for(int d=2;d<=n-1;++d) {
    for(int i=1;i<=n-d;++i) {
      int j = i + d;
      for(int k=i;k<j;++k) {
        int _tmp = dp[i][k]+dp[k+1][j]+a[i][0]*a[k][1]*a[j][1];
        if(!dp[i][j]) dp[i][j] = _tmp;
        else dp[i][j] = min(dp[i][j], _tmp);
      }
    }
  }
  cout << dp[1][n] << '\n';
  return 0;
}