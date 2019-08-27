#include <iostream>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans; cin >> n;
  if(n==1) ans = 1;
  else if(n==2) ans = 2;
  int a = 1, b = 2;
  for(int i=3;i<=n;++i) {
    ans = (a + b) % 10;
    a = b; b = ans;
  }
  cout << ans << '\n';
  return 0;
}