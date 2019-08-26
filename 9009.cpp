#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll fibo[46];

void prep(void) {
  fibo[0] = 0, fibo[1] = 1;
  for(int i=2;i<46;++i)
    fibo[i] = fibo[i-1] + fibo[i-2];
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  prep();
  while(tc--) {
    vector<int> ans;
    ll n; cin >> n;
    int i = 45;
    while(n) {
      if(fibo[i] <= n) {
        n -= fibo[i];
        ans.push_back(fibo[i]);
      } else i--;
    }
    reverse(ans.begin(), ans.end());
    for(int i=0;i<ans.size();++i) cout << ans[i] << ' ';
    cout << '\n';
  }
  return 0;
}