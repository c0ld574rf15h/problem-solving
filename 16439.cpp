#include <iostream>
using namespace std;

int arr[30][30];

int max3(int a, int b, int c) {
  return max(max(a, b), c);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, ans = 0; cin >> n >> m;
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      cin >> arr[i][j];
  for(int i=0;i<m;++i) {
    for(int j=i+1;j<m;++j) {
      for(int k=j+1;k<m;++k) {
        int cur = 0;
        for(int c=0;c<n;++c)
          cur += max3(arr[c][i], arr[c][j], arr[c][k]);
        ans = max(ans, cur);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}