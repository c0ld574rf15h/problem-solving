#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  while(tc--) {
    bool flag = false;
    ll m, n, x, y; cin >> m >> n >> x >> y;
    ll _lcm = lcm(m, n);
    while(x <= _lcm) {
      if(x%n==y%n) {
        flag = true;
        cout << x << '\n';
        break;
      }
      x += m;
    }
    if(!flag)
      cout << -1 << '\n';
  }
  return 0;
}