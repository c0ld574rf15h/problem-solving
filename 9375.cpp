#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  while(tc--) {
    map<string, int> m;
    int n; cin >> n;
    for(int i=0;i<n;++i) {
      string a, b; cin >> a >> b;
      m[b] ? m[b]++ : m[b]=1;
    }
    int ans = 1;
    for(auto it=m.begin();it!=m.end();++it) ans *= it->second+1;
    ans -= 1;
    cout << ans << '\n';
  }
  return 0;
}