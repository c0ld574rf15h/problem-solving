#include <iostream>
using namespace std;

int a[1001];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for(int i=0;i<n;++i) {
    int x, y, z; cin >> x >> y >> z;
    a[x] += z; a[y] -= z;
  }
  int cur = 0, ans = 0;
  for(int i=1;i<=1000;++i) {
    cur += a[i];
    ans = max(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}