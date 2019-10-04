#include <iostream>
using namespace std;

int a[1111], dp[1001][1001];  // i jumps --> land on k

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool flag = false;
  int N; cin >> N;
  for(int i=0;i<N;++i) cin >> a[i];
  dp[0][0] = 1;
  for(int i=0;i<N;++i) {
    for(int j=0;j<N;++j) {
      if(dp[j][i]) {
        for(int k=0;k<=a[i];++k) {
          dp[j+1][i+k] = 1;
        }
      }
    }
  }
  for(int i=0;i<N;++i) {
    if(dp[i][N-1]) {
      cout << i << '\n'; flag = true;
      break;
    }
  }
  if(!flag) cout << -1 << '\n';
  return 0;
}