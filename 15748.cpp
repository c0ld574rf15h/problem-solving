#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll L, N, f, b;
vector<pll> stop;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> L >> N >> f >> b;
  for(int i=0;i<N;++i) {
    ll a, b; cin >> a >> b;
    stop.push_back(make_pair(b, -a));
  }
  sort(stop.begin(), stop.end(), greater<pll>());
  ll cur = 0, ans = 0;
  for(int i=0;i<N;++i) {
    ll next = -stop[i].second;
    if(cur > next) continue;
    ans += (f-b)*(next-cur)*stop[i].first;
    cur = next;
  }
  cout << ans << '\n';
  return 0;
}