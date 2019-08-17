#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, x, y; cin >> a >> b >> x >> y;
  cout << min(abs(a-b), min(abs(a-x)+abs(b-y), abs(a-y)+abs(b-x))) << '\n';
  return 0;
}