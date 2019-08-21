#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b; cin >> a >> b;
  int alen=a.size(), blen=b.size();
  for(int i=1;i<=alen;++i) {
    for(int j=1;j<=blen;++j) {
      dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
      if(a[i-1]==b[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
    }
  }
  cout << dp[alen][blen] << '\n';
  return 0;
}