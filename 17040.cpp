#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vec[101];
vector<int> ans(101, 0);

bool isValid(int cur, int grs) {
  for(int i=0;i<vec[cur].size();++i)
    if(ans[vec[cur][i]]==grs)
      return false;
  return ans[cur]==0;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for(int i=0;i<m;++i) {
    int a, b; cin >> a >> b;
    vec[a].push_back(b); vec[b].push_back(a);
  }
  for(int grs=1;grs<=4;++grs)
    for(int i=1;i<=n;++i)
      if(isValid(i, grs))
        ans[i]=grs;
  for(int i=1;i<=n;++i) cout << ans[i];
  cout << '\n'; return 0;
}