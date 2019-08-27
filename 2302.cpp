#include <iostream>
using namespace std;

bool vip[41];
int dp[41];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(vip, false, sizeof(vip));
  int n, m; cin >> n >> m;
  for(int i=0;i<m;++i) {
    int x; cin >> x;
    vip[x] = true;
  }
  dp[0] = dp[1] = 1;
  for(int i=2;i<=n;++i) {
    if(vip[i] || vip[i-1]) dp[i] = dp[i-1];
    else dp[i] = dp[i-1] + dp[i-2];
  }
  cout << dp[n] << '\n';
  return 0;
}