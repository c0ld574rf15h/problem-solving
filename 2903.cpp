#include <iostream>
using namespace std;
typedef long long ll;

ll _pow(ll b, ll e) {
  ll ret = 1;
  while(e) {
    if(e%2==1) ret *= b;
    b *= b; e >>= 1;
  }
  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  cout << _pow(_pow(2, n) + 1, 2) << '\n';
  return 0;
}