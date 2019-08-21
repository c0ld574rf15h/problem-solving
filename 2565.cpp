#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

vector<pii> vec;
vector<int> a, dp;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for(int i=0;i<n;++i) {
    int a, b; cin >> a >> b;
    vec.push_back(make_pair(a, b));
  }
  sort(vec.begin(), vec.end());
  for(int i=0;i<vec.size();++i) a.push_back(vec[i].second);
  dp.resize(n, 1);
  for(int i=0;i<n;++i)
    for(int j=0;j<i;++j)
      if(a[j]<a[i] && dp[j]>=dp[i])
        dp[i]=dp[j]+1;
  sort(dp.begin(), dp.end(), greater<int>());
  cout << n-dp[0] << '\n';
  return 0;
}