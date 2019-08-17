#include <iostream>
using namespace std;
typedef pair<int, int> pii;

int n, b;
int depth[250];
pii boots[250];
int dp[250][250];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> b;
  for(int i=0;i<n;++i) cin >> depth[i];
  for(int i=0;i<b;++i) cin >> boots[i].first >> boots[i].second;
  dp[0][0] = true;
  for(int i=0;i<n;++i) {
    for(int j=0;j<b;++j) {
      if(dp[i][j]) {
        for(int k=j+1;k<b;++k)
          dp[i][k] = depth[i] <= boots[k].first ? true : false;
        for(int k=1;k<=boots[j].second;++k)
          dp[i+k][j] = depth[i+k] <= boots[j].first ? true : false;
      }
    }
  }
  for(int i=0;i<b;++i) {
    if(dp[n-1][i]) {
      cout << i << '\n';
      break;
    }
  }
  return 0;
}