#include <iostream>
using namespace std;
typedef long long ll;

int_fast64_t dp[1000001];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  dp[1]=1; dp[2]=2;
  for(int i=3;i<=n;++i) dp[i] = (dp[i-1] + dp[i-2]) % 15746;
  cout << dp[n] << '\n';
  return 0;
}