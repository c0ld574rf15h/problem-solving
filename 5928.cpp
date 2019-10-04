#include <iostream>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c; cin >> a >> b >> c;
  int end = a * 1440 + b * 60 + c;
  int base = 11 * 1440 + 11 * 60 + 11;
  if(end >= base) cout << end - base << '\n';
  else cout << -1 << '\n';
  return 0;
}